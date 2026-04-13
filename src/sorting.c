#include "../includes/commons.h" 

void bubbleSort(Deportista* arr, int size, Comparador cmp) {
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
}

void insertionSort(Deportista* arr, int size, Comparador cmp) {
    for (int i = 1; i < size; i++) {
        Deportista key = arr[i]; // Elemento a insertar
        int j = i - 1;
        while (j >= 0 && cmp(&arr[j], &key) > 0) { 
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(Deportista* arr, int size, Comparador cmp) {
    for (int i = 0; i < size-1; i++) {
        int min_idx = i;
        for (int j = i+1; j < size; j++) {
            if (cmp(&arr[j], &arr[min_idx]) < 0) {
                min_idx = j;
            }
        }
        Deportista temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

void cocktailSort(Deportista* arr, int size, Comparador cmp) {
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
}


