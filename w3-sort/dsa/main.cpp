#include "merge-sort.h"
#include "time.h"

#include <cstdlib>
#include<iostream>
using namespace std;

int main() {
    srand(time(0));
    int size = 100000000;
    int* array = new int[size];
    for (int i = 0; i < size; i++) {
        array[i] = rand();
    }

    mergeSort(array, size);
    for (int i = 0; i < size; i++) {
        cout << "After: " << array[i] << endl; 
    }

    return 0;
}