#include "../includes/commons.h"

#define MAX 500

char nombres[MAX][50];
char apellidos[MAX][50];
int totalNombres = 0;
int totalApellidos = 0;

void LeerNombresApellidos(){

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
} // N^2 * N^2 = N^4

void CreaCsv(int itemsPorCrear){

    int puntaje=0, cantidadCompetencias=0;
    char pathCsv[1024];

    // Crear path correcto
    srand(time(0));
    snprintf(pathCsv, sizeof(pathCsv), "db/deportistas%d.csv", itemsPorCrear);

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

    fprintf(archivo,"ID,Nombre,Equipo,Puntaje,cantidadCompetencias\n");
    for (int i = 1; i <= itemsPorCrear; i++){
        int randomNombre = rand() % totalNombres;
        int randomApellido = rand() % totalApellidos;
        puntaje = rand() % 100;
        cantidadCompetencias = rand() % 5000;
        fprintf(
            archivo, "%d,%s %s, Huachipato,%d,%d\n", 
            i, nombres[randomNombre], apellidos[randomApellido], puntaje, cantidadCompetencias
        );
    }

    fclose(archivo);
    printf("\033[0;32mCSV de deportistas creado con %d registros.\033[0m\n", itemsPorCrear);
    
    // Actualizar db/tools/opciones.csv
    FILE *opciones = fopen("db/tools/opciones.csv", "a");
    if (opciones != NULL) {
        fprintf(opciones, "%d\n", itemsPorCrear);
        fclose(opciones);
    } else {
        printf("Advertencia: No se pudo actualizar db/tools/opciones.csv\n");
    }
}

void ListarCsvDisponibles(){
    
    int cont = 1;
    char path[1024];
    char line[128];
    FILE *opciones = fopen("db/tools/opciones.csv", "r");
    if (opciones == NULL) {
        printf("Error al abrir db/tools/opciones.csv\n");
        return;
    }

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
        } else {
            printf("Opción %s no encontrada, se ha eliminado.\n", line);
        }
    }

    fclose(opciones);
    fclose(temp);

    remove ("db/tools/opciones.csv"); // Eliminar archivo original
    rename ("db/tools/opciones_temp.csv", "db/tools/opciones.csv"); // Renombrar archivo temporal

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

void OrdenaCsv(){
    
}

void BuscarPorID(){

}

void Ranking(){

}