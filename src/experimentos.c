#include "../includes/commons.h"

void ExperimentoOrdenamiento(AlgoritmoOrdenamiento algoritmo, Comparador cmp){
    clock_t start_t, end_t;
    double mejor_caso_t, peor_caso_t, caso_promedio_t;

    // Mejor caso: ordenar un arreglo ya ordenado
    algoritmo(deportistas, cantItems, cmp);
    start_t = clock();
    algoritmo(deportistas, cantItems, cmp);
    end_t = clock();
    mejor_caso_t = ((double)(end_t - start_t)) / CLOCKS_PER_SEC;

    // Peor caso: ordenar un arreglo ordenado en orden inverso
    InvertirArreglo(deportistas, cantItems, cmp);
    start_t = clock();
    algoritmo(deportistas, cantItems, cmp);
    end_t = clock();
    peor_caso_t = ((double)(end_t - start_t)) / CLOCKS_PER_SEC;

    // Caso promedio: ordenar un arreglo desordenado (mezclar antes de ordenar)
    FisherYatesShuffle(deportistas, cantItems);
    start_t = clock();
    algoritmo(deportistas, cantItems, cmp);
    end_t = clock();
    caso_promedio_t = ((double)(end_t - start_t)) / CLOCKS_PER_SEC;
    printf("\033[0;34m[Experimento] Mejor caso: %.6f segundos\033[0m\n", mejor_caso_t);
    printf("\033[0;34m[Experimento] Peor caso: %.6f segundos\033[0m\n", peor_caso_t);
    printf("\033[0;34m[Experimento] Caso promedio: %.6f segundos\033[0m\n", caso_promedio_t);

}

void ExperimentoBusqueda(AlgoritmoBusqueda algoritmo, int targetID){
    // Implementar función para experimentar complejidad temporal de algoritmos de búsqueda
}