#include "../includes/commons.h" 

void bubbleSort(Deportista* arr, int size, Comparador cmp) {
    clock_t start_t, end_t;

    start_t = clock();
    int swapped = 0;
    for (int i = 0; i < size-1; i++){
        swapped = 0;
        for (int j = 0; j < size-i-1; j++){
            // Usamos el callback para comparar los elementos
            if (cmp(&arr[j], &arr[j+1]) > 0) {
                Deportista temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
                swapped++;
            }
        }
        if (swapped == 0) break; // No se hicieron intercambios, el arreglo ya está ordenado
    }
    end_t = clock();
    double tiempo_usado = ((double)(end_t - start_t)) / CLOCKS_PER_SEC;
    printf("\033[0;34m[Bubble]Tiempo de ejecución: %.6f segundos\033[0m\n", tiempo_usado);
}

void insertionSort(Deportista* arr, int size, Comparador cmp) {
    clock_t start_t, end_t;
    start_t = clock();
    for (int i = 1; i < size; i++) {
        Deportista key = arr[i]; // Elemento a insertar
        int j = i - 1;
        while (j >= 0 && cmp(&arr[j], &key) > 0) { 
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    end_t = clock();
    double tiempo_usado = ((double)(end_t - start_t)) / CLOCKS_PER_SEC;
    printf("\033[0;34m[Insertion]Tiempo de ejecución: %.6f segundos\033[0m\n", tiempo_usado);
}

void selectionSort(Deportista* arr, int size, Comparador cmp) {
    clock_t start_t, end_t;
    start_t = clock();
    for (int i = 0; i < size-1; i++) {
        int min_idx = i;
        for (int j = i+1; j < size; j++) {
            if (cmp(&arr[j], &arr[min_idx]) < 0) {
                min_idx = j;
            }
        }

        // optimización
        if (min_idx != i) {
            Deportista temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }
    }
    end_t = clock();
    double tiempo_usado = ((double)(end_t - start_t)) / CLOCKS_PER_SEC;
    printf("\033[0;34m[Selection]Tiempo de ejecución: %.6f segundos\033[0m\n", tiempo_usado);
}

void cocktailSort(Deportista* arr, int size, Comparador cmp) {
    clock_t start_t, end_t;
    start_t = clock();
    
    int swapped = 1;
    int start = 0;
    int end = size - 1;

    while (swapped) {
        swapped = 0;

        for (int i = start; i < end; i++) {
            if (cmp(&arr[i], &arr[i + 1]) > 0) {
                Deportista temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = 1;
            }
        }

        if (!swapped) break;

        swapped = 0;
        end--;

        for (int i = end; i >= start; i--) {
            if (cmp(&arr[i], &arr[i + 1]) > 0) {
                Deportista temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = 1;
            }
        }
        start++;
    }

    end_t = clock();
    double tiempo_usado = ((double)(end_t - start_t)) / CLOCKS_PER_SEC;
    printf("\033[0;34m[Cocktail]Tiempo de ejecución: %.6f segundos\033[0m\n", tiempo_usado);
}

void fisherYatesShuffle(Deportista* arr, int size) {
    
    srand(time(0));
    Deportista temp;

    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1); // Índice aleatorio entre 0 e i
        
        // Swap
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}


