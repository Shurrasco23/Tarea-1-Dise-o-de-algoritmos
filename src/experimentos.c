#include "../includes/commons.h"

void ExperimentoOrdenamiento(AlgoritmoOrdenamiento algoritmo, Comparador cmp, double resultados[3]){
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
    // Dado que el arreglo es desordenado al azar, vamos a sacar 
    // el promedio de 5 ejecuciones para tener una mejor estimación del caso promedio
    
    for (int i = 0; i < 5; i++) {
        FisherYatesShuffle(deportistas, cantItems);
        start_t = clock();
        algoritmo(deportistas, cantItems, cmp);
        end_t = clock();
        caso_promedio_t += ((double)(end_t - start_t)) / CLOCKS_PER_SEC;
    }
    caso_promedio_t /= 5.0; // Sacar el promedio dividiendo por la cantidad de ejecuciones

    resultados[0] = mejor_caso_t;
    resultados[1] = peor_caso_t;
    resultados[2] = caso_promedio_t;

    return;
}

double ExperimentoBusqueda(AlgoritmoBusqueda algoritmo, int targetID){
    clock_t start_t, end_t;
    double peor_caso_t;
    int resultado, idPorEncontrar = 0; // ID que no existe en el arreglo para simular el peor caso

    start_t = clock();
    resultado = algoritmo(deportistas, cantItems, idPorEncontrar);
    end_t = clock();
    peor_caso_t = ((double)(end_t - start_t)) / CLOCKS_PER_SEC;
    printf("\033[0;34m[Experimento] Búsqueda del ID %d: %s en %.6f segundos\033[0m\n", targetID, resultado != -1 ? "Encontrado" : "No encontrado", peor_caso_t);

    start_t = clock();
    resultado = algoritmo(deportistas, cantItems, idPorEncontrar);
    end_t = clock();
    peor_caso_t = ((double)(end_t - start_t)) / CLOCKS_PER_SEC;
    printf("\033[0;34m[Experimento] Búsqueda del ID %d: %s en %.6f segundos\033[0m\n", idPorEncontrar, resultado != -1 ? "Encontrado" : "No encontrado", peor_caso_t);

    return peor_caso_t;
}

