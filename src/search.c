#include "../includes/commons.h" 

int binarySearchID(Deportista *arr, int size, int targetID) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid].ID == targetID) {
            return mid; 
        }

        if (arr[mid].ID < targetID) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return -1; // No encontrado
}