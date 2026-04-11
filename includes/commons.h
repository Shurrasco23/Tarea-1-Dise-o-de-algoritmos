#ifndef TAREA_H
#define TAREA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX_NOMBRE 64
#define MAX_EQUIPO 64

typedef struct{
    int ID;
    char nombre[MAX_NOMBRE];
    char equipo[MAX_EQUIPO];
    double puntaje;
    int cantidadCompetencias;
} Deportista;

extern Deportista* deportistas; // Declaración del arreglo global de deportistas
extern int cantItems; // Declaración del contador global de deportistas

// Callback para manejar el ordenamiento por diferentes campos
typedef int (*Comparador)(const Deportista* a, const Deportista* b);

// CSV
void LeerNombresApellidos();
void CreaCsv(int itemsPorCrear);
void LeerCsvDeportistas(const char* filename);
int ExtraerCantidadDeFilename(const char* filename);
int ListarCsvDisponibles(int itemsPorCrear);

// Menu 
void Menu();
void OrdenaCsv();
void BuscarPorID();
void Ranking();
void showFirst10Deportistas();
// Validaciones 
bool sePuedeOrdenar();
bool existenCSV(const char *filename, int itemsPorCrear);

// Algoritmos de ordenamiento}
// Callbacks para ordenamiento
int CmpPorID(const Deportista* a, const Deportista* b);
int CmpPorNombre(const Deportista* a, const Deportista* b);
int CmpPorEquipo(const Deportista* a, const Deportista* b);
int CmpPorPuntaje(const Deportista* a, const Deportista* b);
int CmpPorCompetencias(const Deportista* a, const Deportista* b);

// Bubble Sort con callback
void bubbleSort(Deportista* arr, int size, Comparador cmp);
void insertionSort(Deportista* arr, int size, Comparador cmp);

#endif