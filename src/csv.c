#include "../includes/tarea.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 500

char nombres[MAX][50];
char apellidos[MAX][50];
int totalNombres = 0;
int totalApellidos = 0;

void leer_nombres_y_apellidos(){

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

void CreaCsv(){

    int id = 1;
    int puntaje=0, cantidadCompetencias=0;

    srand(time(0));

    FILE *archivo = fopen("db/deportistas.csv", "w");
    if (archivo == NULL) {
        printf("Error al crear db/deportistas.csv\n");
        return;
    }

    leer_nombres_y_apellidos();
    if (totalNombres == 0 || totalApellidos == 0) {
        printf("No hay nombres o apellidos disponibles para crear el CSV.\n");
        return;
    }

    fprintf(archivo,"ID,Nombre,Equipo,Puntaje,CantidadCompetencias\n");
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

void OrdenaCsv(){
    
}

void BuscarPorID(){

}

void Ranking(){

}