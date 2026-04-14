#include "../includes/commons.h"

void FisherYatesShuffle(Deportista* arr, int size) {
    
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
