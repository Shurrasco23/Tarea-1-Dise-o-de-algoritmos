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

// Estructura para representar a un deportista
typedef struct{
    int ID;
    char nombre[MAX_NOMBRE];
    char equipo[MAX_EQUIPO];
    double puntaje;
    int cantidadCompetencias;
} Deportista;

// Estructura para medir tiempos de ejecución
typedef struct {
    clock_t start;
    clock_t end;
    double cpu_time_used;
} ExecTime;

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
void BuscarPorIDBinario();
void Ranking();
void showFirst10Deportistas();
// Validaciones 
bool sePuedeIterar();

// Algoritmos de ordenamiento
// Callbacks para ordenamiento
int CmpPorID(const Deportista* a, const Deportista* b);
int CmpPorNombre(const Deportista* a, const Deportista* b);
int CmpPorEquipo(const Deportista* a, const Deportista* b);
int CmpPorPuntaje(const Deportista* a, const Deportista* b);
int CmpPorCompetencias(const Deportista* a, const Deportista* b);

// Bubble Sort con callback
void bubbleSort(Deportista* arr, int size, Comparador cmp);
void insertionSort(Deportista* arr, int size, Comparador cmp);
void selectionSort(Deportista* arr, int size, Comparador cmp);
void cocktailSort(Deportista* arr, int size, Comparador cmp);

// Algoritmos de búsqueda
int busquedaBinaria(Deportista *arr, int size, int targetID); // Busqueda binaria para el ID
int busquedaSecuencial(Deportista *arr, int size, int targetID);
#endif