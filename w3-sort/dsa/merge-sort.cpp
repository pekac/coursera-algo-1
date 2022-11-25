#include "merge-sort.h"

#include<iostream>
using namespace std;

void merge(int* array, int* tempArray, int lo, int mid, int hi) {
    for (int k = lo; k <= hi; k++) {
        tempArray[k] = array[k];
    }

    int i = lo;
    int j = mid + 1;
    for (int k = lo; k <= hi; k++) {
        if (i > mid) {
            array[k] = tempArray[j];
            j++;
        } else if (j > hi || tempArray[i] <= tempArray[j]) {
            array[k] = tempArray[i];
            i++;
        } else {
            array[k] = tempArray[j];
            j++;
        }
    }
}

void sort(int* array, int* tempArray, int lo, int hi) {
    if (hi <= lo) return;
    int mid = lo + (hi - lo) / 2;
    sort(array, tempArray, lo, mid);
    sort(array, tempArray, mid + 1, hi);
    merge(array, tempArray, lo, mid, hi);
}

void mergeSort(int* array, int n) {
    int* tempArray = new int[n];
    sort(array, tempArray, 0, n - 1);
}
