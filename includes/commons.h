#ifndef TAREA_H
#define TAREA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NOMBRE 64
#define MAX_EQUIPO 64

typedef struct{
    int ID;
    char nombre[MAX_NOMBRE];
    char equipo[MAX_NOMBRE];
    double puntaje;
    int cantidadCompetencias;
} Deportista;

extern Deportista* deportistas; // Declaración del arreglo global de deportistas
extern int cantItems; // Declaración del contador global de deportistas

// CSV
void LeerNombresApellidos();
void CreaCsv(int itemsPorCrear);
void LeerDeportistas(const char* filename);
int ExtraerCantidadDeFilename(const char* filename);
// Menu 
void Menu();
// Algoritmos de ordenamiento y busqueda
void OrdenaCsv();
void BuscarPorID();
void Ranking();
#endif