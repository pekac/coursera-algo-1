#include "quicksort.h"
#include <bits/stdc++.h>

#include<iostream>
using namespace std;

int partition(int* array, int lo, int hi) {
    int i = lo;
    int j = hi + 1;
    while (true) {
        while (array[lo] > array[i] && i < hi) {
            i++;
        }

        while (array[lo] < array[j] && j > lo) {
            j--;
        }

        if (i >= j) {
            break;
        }

        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
    return j;
}

void sort(int* array, int lo, int hi) {
    if (hi <= lo) {
        return;
    }

    int j = partition(array, lo, hi);
    sort(array, lo, j-1);
    sort(array, j+1, hi);
}

void quickSort(int* array, int size) {
    shuffle(array, array + size, default_random_engine(0));
    sort(array, 0, size - 1);
}

void quickSortThreeWay(int* array, int lo, int hi) {
    if (hi <= lo) return;
    int lt = lo;
    int gt = hi;
    int v = array[lo];
    int i = lo;
    while (i <= gt) {
        if (array[i] < v) {
            int temp = array[i];
            array[i] = array[lt];
            array[lt] = temp;
            
            i++;
            lt++;
        } else if (array[i] > v) {
            int temp = array[i];
            array[i] = array[gt];
            array[gt] = temp;
            
            gt--;
        } else {
            i++;
        }
    }

    quickSortThreeWay(array, lo, lt - 1);
    quickSortThreeWay(array, gt + 1, hi);
}
   