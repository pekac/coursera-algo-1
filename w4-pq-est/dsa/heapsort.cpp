#include "heapsort.h"

void heapsort(int* array, int size) {
    int half = (size - 1) % 2 == 0 ? ((size - 1) - 2) / 2 : (size - 1) / 2;
    for (int i = half; i >= 0; i--) {
        sink(array, i, size);
    }

    while(size > 1) {
        swap(array, 0, size - 1);
        size--;
        sink(array, 0, size);
    }
}

void sink(int* array, int i, int size) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left >= size) {
        return;
    }

    int swapIndex = right > size - 1 ? left : array[left] > array[right] ? left : right;

    if  (array[i] < array[swapIndex]) {
        swap(array, i, swapIndex);
        sink(array, swapIndex, size);
    }
}


void swap(int* array, int i, int j) {
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}
