#include "../includes/commons.h"

#define MAX 500

char nombres[MAX][50];
char apellidos[MAX][50];
int totalNombres = 0;
int totalApellidos = 0;

void LeerNombresApellidos(){

    FILE *archivoNombres = fopen("db/nombres.csv", "r"); // leer archivo Nombres.csv
    FILE *archivoApellidos = fopen("db/apellidos.csv", "r"); // leer archivo Apellidos.csv

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

    int id = 1;
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
    for (int i = 0; i < totalNombres; i++){
        for (int j = 0; j < totalApellidos; j++){
            puntaje = rand() % 100;
            cantidadCompetencias = rand() % 5000;
            fprintf(archivo, "%d,%s %s, Huachipato,%d,%d\n", id, nombres[i], apellidos[j], puntaje, cantidadCompetencias);
            id++;
        }
    }

    fclose(archivo);
    printf("\033[0;32mCSV de deportistas creado con %d registros.\033[0m\n", id - 1);
}

void LeerDeportistas(const char* filename){

    int currItem = 0;
    char linea[1024];

    // Extraer cantidad de deportistas del nombre del archivo
    cantItems = ExtraerCantidadDeFilename(filename);
    if (cantItems <= 0) {
        printf("Error: No se pudo extraer la cantidad de deportistas del nombre del archivo '%s'.", filename);
        return;
    }

    printf("\033[0;33mCargando %d deportistas desde '%s'...\033[0m\n", cantItems, filename);

    // Crear path completo
    char path[1024];
    snprintf(path, sizeof(path), "db/%s", filename);

    // Abrir archivo
    FILE *archivo = fopen(path, "r");
    if (archivo == NULL) {
        printf("Error al abrir db/%s\n", filename);
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

int ExtraerCantidadDeFilename(const char* filename) {
    // Expected format: "deportistas123.csv"
    int count = 0;
    if (sscanf(filename, "deportistas%d.csv", &count) == 1) {
        return count;
    }
    return -1;  // Error: couldn't parse
}

void OrdenaCsv(){
    
}

void BuscarPorID(){

}

void Ranking(){

}