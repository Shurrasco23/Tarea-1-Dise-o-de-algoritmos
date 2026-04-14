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

// Callback para experimentar con distintos algoritmos de ordenamiento
typedef void (*AlgoritmoOrdenamiento)(Deportista* arr, int size, Comparador cmp);

// Callbacks para experimentar con distintos algoritmos de búsqueda
typedef int (*AlgoritmoBusqueda)(Deportista *arr, int size, int targetID);

// CSV
void LeerNombresApellidos();
void CreaCsv(int itemsPorCrear);
void LeerCsvDeportistas(const char* filename);
int ExtraerCantidadDeFilename(const char* filename);
int ListarCsvDisponibles(int itemsPorCrear);

// Menu 
void Menu();
void OpcionOrdenarCsv();
void BuscarPorIDBinario();
void Ranking(int numRankingMostrar);
void showFirst10Deportistas();
// Validaciones 
bool HayDeportistasCargados();

// Algoritmos de ordenamiento
// Callbacks para ordenamiento
int CmpPorID(const Deportista* a, const Deportista* b);
int CmpPorNombre(const Deportista* a, const Deportista* b);
int CmpPorEquipo(const Deportista* a, const Deportista* b);
int CmpPorPuntaje(const Deportista* a, const Deportista* b);
int CmpPorCompetencias(const Deportista* a, const Deportista* b);

// Algoritmos de ordenamiento
void BubbleSort(Deportista* arr, int size, Comparador cmp);
void InsertionSort(Deportista* arr, int size, Comparador cmp);
void SelectionSort(Deportista* arr, int size, Comparador cmp);
void CocktailSort(Deportista* arr, int size, Comparador cmp);
void InvertirArreglo(Deportista* arr, int size, Comparador cmp);

// Algoritmo de shuffle para crear CSV desordenados
void FisherYatesShuffle(Deportista* arr, int size);

// Algoritmos de búsqueda
int BusquedaBinaria(Deportista *arr, int size, int targetID); // Busqueda binaria para el ID
int BusquedaSecuencial(Deportista *arr, int size, int targetID);

// Experimentos
void ExperimentoOrdenamiento(AlgoritmoOrdenamiento algoritmo, Comparador cmp);
void ExperimentoBusqueda(AlgoritmoBusqueda algoritmo, int targetID);
#endif