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
        Deportista key = arr[i];
        int j = i - 1;
        while (j >= 0 && cmp(&arr[j], &key) > 0) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}



