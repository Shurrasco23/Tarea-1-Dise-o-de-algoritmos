#include "../includes/commons.h"

#define MAX 500

char nombres[MAX][50];
char apellidos[MAX][50];
char* equipos[] = {
    "Huachipato", "Colo-Colo", "Universidad de Chile", 
    "La Serena", "Everton", "Palestino"
};
int totalNombres = 0;
int totalApellidos = 0;
int totalEquipos = 6;


void LeerNombresApellidos(){

    totalNombres = 0;
    totalApellidos = 0;

    FILE *archivoNombres = fopen("db/tools/nombres.csv", "r"); // leer archivo Nombres.csv
    FILE *archivoApellidos = fopen("db/tools/apellidos.csv", "r"); // leer archivo Apellidos.csv

    if (archivoNombres == NULL || archivoApellidos == NULL) {
        printf("Error al abrir los archivos de nombres o apellidos.\n");
        return;
    }

    char linea[1024];

    // Leer nombres
    while (fgets(linea, sizeof(linea), archivoNombres)){
        char *token = strtok(linea, ",\n");
        while (token != NULL && totalNombres < MAX){
            token[strcspn(token, "\r\n")] = 0; // Eliminar saltos de línea
            strcpy(nombres[totalNombres], token);
            totalNombres++;
            token = strtok(NULL, ",\n");
        }
    }

    // Leer apellidos
    while (fgets(linea, sizeof(linea), archivoApellidos)){
        char *token = strtok(linea, ",\n");
        while (token != NULL && totalApellidos < MAX){
            token[strcspn(token, "\r\n")] = 0; // Eliminar saltos de línea
            strcpy(apellidos[totalApellidos], token);
            totalApellidos++;
            token = strtok(NULL, ",\n");
        }
    }

    fclose(archivoNombres);
    fclose(archivoApellidos);
} 

void CreaCsv(int itemsPorCrear){

    int competenciasRandom = 0, nombreRandom = 0, apellidoRandom = 0, equipoRandom = 0;
    double puntajeRandom = 0;
    char nombreCompleto[100];
    char pathCsv[1024];
    Deportista nuevoCsv[itemsPorCrear];

    // Crear path correcto
    srand(time(0));
    snprintf(pathCsv, sizeof(pathCsv), "db/deportistas%d.csv", itemsPorCrear);

    // Comprobamos si el archivo existe antes de crearlo para evitar agregar opciones duplicadas en opciones.csv
    bool archivoYaExiste = access(pathCsv, F_OK) == 0;

    FILE *archivo = fopen(pathCsv, "w");
    if (archivo == NULL) {
        printf("Error al crear %s\n", pathCsv);
        return;
    }

    LeerNombresApellidos();
    if (totalNombres == 0 || totalApellidos == 0) {
        printf("No hay nombres o apellidos disponibles para crear el CSV.\n");
        return;
    }

    
    for (int i = 0; i < itemsPorCrear; i++){
        nombreRandom = rand() % totalNombres;
        apellidoRandom = rand() % totalApellidos;
        equipoRandom = rand() % totalEquipos;
        puntajeRandom = ((double)rand() / RAND_MAX) * 100.0;
        competenciasRandom = rand() % 5000;
        snprintf(nombreCompleto, sizeof(nombreCompleto), "%s %s", nombres[nombreRandom], apellidos[apellidoRandom]);
        
        nuevoCsv[i].ID = i + 1;
        strcpy(nuevoCsv[i].nombre, nombreCompleto);
        strcpy(nuevoCsv[i].equipo, equipos[equipoRandom]);
        nuevoCsv[i].puntaje = puntajeRandom;
        nuevoCsv[i].cantidadCompetencias = competenciasRandom;

    }

    fisherYatesShuffle(nuevoCsv, itemsPorCrear); // Mezclar el nuevo CSV para evitar que vengan ordenados por ID

    // Escribir nuevo CSV
    fprintf(archivo,"ID,Nombre,Equipo,Puntaje,cantidadCompetencias\n");
    for (int i = 0; i < itemsPorCrear; i++){
        fprintf(
            archivo, "%d,%s, %s, %.2f, %d\n", 
            nuevoCsv[i].ID,
            nuevoCsv[i].nombre,
            nuevoCsv[i].equipo,
            nuevoCsv[i].puntaje,
            nuevoCsv[i].cantidadCompetencias
        );
    }
    fclose(archivo);
    printf("\033[0;32mCSV de deportistas creado con %d registros.\033[0m\n", itemsPorCrear);
    
   

    if (archivoYaExiste) {
        printf("Archivo ya listado en opciones.csv, no se agregará nuevamente.\n");
        return;
    }

    // Actualizar db/tools/opciones.csv
    FILE *opciones = fopen("db/tools/opciones.csv", "a");
    if (opciones != NULL) {
        fprintf(opciones, "%d\n", itemsPorCrear);
        fclose(opciones);
    } else {
        printf("Advertencia: No se pudo actualizar db/tools/opciones.csv\n");
    }

}

int ListarCsvDisponibles(int itemsPorCrear){
    
    int cont = 1;
    char path[1024];
    char line[128];
      
    FILE *opciones = fopen("db/tools/opciones.csv", "r");
    if (opciones == NULL) {
        printf("\033[0;31mNo se encontraron CSV disponibles en db/. CREE un csv para continuar.\033[0m\n");
        return -1;
    }

    char firstLine[128];
    if (fgets(firstLine, sizeof(firstLine), opciones) == NULL) {
        printf("\033[0;31mNo se encontraron CSV disponibles en db/. CREE un csv para continuar.\033[0m\n");
        fclose(opciones);
        return -1;
    }

    // Reabrir para leer desde el principio
    rewind(opciones);

    // Queremos almacenar solo las opciones que realmente existen, para eso creamos un archivo temporal
    // Luego cargamos al nuevo opciones.csv solo con las opciones válidas, eliminando las que no existen
    FILE *temp = fopen("db/tools/opciones_temp.csv", "w");
    
    printf("\033[0;36mTamaños de CSV disponibles en db/:\033[0m\n");

    while (fgets(line, sizeof(line), opciones)) {
        line[strcspn(line, "\r\n")] = 0; // Eliminar saltos de línea
        
        snprintf(path, sizeof(path), "db/deportistas%s.csv", line); // Crear path completo
        
        // Verificar si el archivo existe
        if (access(path, F_OK) == 0) {
            printf("%d.  %s\n", cont, line);
            fprintf(temp, "%s\n", line); // Guardar solo los que existen
            cont++;
        } else {
            printf("Opción %s no encontrada, se ha eliminado.\n", line);
        }
    }

    fclose(opciones);
    fclose(temp);

    remove ("db/tools/opciones.csv"); // Eliminar archivo original
    rename ("db/tools/opciones_temp.csv", "db/tools/opciones.csv"); // Renombrar archivo temporal
    return 0;
}
// Carga un CSV de
void LeerCsvDeportistas(const char* filename){

    int currItem = 0;
    char linea[1024];

    // Extraer cantidad de deportistas del nombre del archivo
    cantItems = ExtraerCantidadDeFilename(filename);
    if (cantItems <= 0) {
        printf("Error: No se pudo extraer la cantidad de deportistas del nombre del archivo '%s'.", filename);
        return;
    }

    printf("\033[0;33mCargando %d deportistas desde '%s'...\033[0m\n", cantItems, filename);

    // Abrir archivo
    FILE *archivo = fopen(filename, "r");
    if (archivo == NULL) {
        printf("Error al abrir %s\n", filename);
        return;
    }

    // Asignar memoria para lista deportistas
    deportistas = malloc(cantItems * sizeof(Deportista));
    if (deportistas == NULL) {
        printf("Error al asignar memoria para deportistas.\n");
        fclose(archivo);
        return;
    }

    // Leer linea por linea  
    fgets(linea, sizeof(linea), archivo); // Leer encabezado

    while (fgets(linea, sizeof(linea), archivo)) {

        char *token = strtok(linea, ",\n");
        if (token != NULL) deportistas[currItem].ID = atoi(token);

        token = strtok(NULL, ",\n");
        if (token != NULL) strncpy(deportistas[currItem].nombre, token, MAX_NOMBRE);

        token = strtok(NULL, ",\n");
        if (token != NULL) strncpy(deportistas[currItem].equipo, token, MAX_EQUIPO);

        token = strtok(NULL, ",\n");
        if (token != NULL) deportistas[currItem].puntaje = atof(token);

        token = strtok(NULL, ",\n");
        if (token != NULL) deportistas[currItem].cantidadCompetencias = atoi(token);

        currItem++;
    }

    fclose(archivo);
    printf("\033[0;32mDeportistas cargados: %d\033[0m\n", currItem);

}

// Función para extraer la cantidad de items del nombre del archivo.
int ExtraerCantidadDeFilename(const char* filename) {
    // Formato esperado: "db/deportistas123.csv"
    int count = 0;
    if (sscanf(filename, "db/deportistas%d.csv", &count) == 1) {
        return count;
    }
    return -1;  // Error: no se pudo extraer la cantidad
}

// Funcion para obligar al usuario a cargar un CSV, si no hay deportistas cargados no se puede ordenar ningun campo
bool sePuedeIterar(){
    if (deportistas == NULL) {
        printf("\033[0;31mNo hay deportistas cargados para hacer iteraciones, CARGUE un deportistas<cantidad>.csv\033[0m\n");
        return false;
    }
    return true;
}

void BuscarPorIDBinario(){

    if (!sePuedeIterar()) return; // Validar que hay deportistas cargados
    
    printf ("\033[0;33mBusqueda por ID: \033[0m\n");
    printf ("Ingresar -2 para salir de la busqueda por ID\n");

    int targetID;

    do {
        printf ("Ingrese el ID del deportista que desea buscar: ");
        while (scanf("%d", &targetID)!=1){
            printf ("\033[0;31mNo se admiten letras solo numeros: \033[0m");
            if (targetID == -2){
                printf ("Saliendo de busqueda por ID");
                break;
            }
            while (getchar() != '\n'); // Limpiar el buffer de entrada
        }

        int index = busquedaBinaria(deportistas, cantItems, targetID);

        if (index != -1) {
            printf ("\033[0;32mDeportista encontrado: [%d]\033[0m \n", targetID);
            printf("%-5s %-25s %-15s %-10s %s\n", "ID", "Nombre", "Equipo", "Puntaje", "Competencias");
            printf ("-------------------------------------------------------------\n");
            printf("%-5d %-20s %-15s %-10.2f %d\n", 
                deportistas[index].ID, 
                deportistas[index].nombre, 
                deportistas[index].equipo, 
                deportistas[index].puntaje, 
                deportistas[index].cantidadCompetencias
            );
            printf ("-------------------------------------------------------------\n");
        }

        else {
            printf ("\033[0;31mDeportista no encontrado: [%d]\033[0m\n", targetID);
        }
    } while (targetID != -2);
}

void Ranking(){

}

