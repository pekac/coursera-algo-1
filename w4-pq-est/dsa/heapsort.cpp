#include "heapsort.h"

void heapsort(int* array, int size) {
    int half = size % 2 == 0 ? size / 2 : (size - 1) / 2;
    for (int i = half; i > 0; i--) {
        sink(array, i, size);
    }

    while(size > 1) {
        swap(array, 1, size - 1);
        size--;
        sink(array, 1, size);
    }

}

void sink(int* array, int i, int size) {
    if (i >= size - 2) {
        return;
    }

    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int swapIndex = array[left] > array[right] ? left : right;

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
