#include "heapsort.h"

#include<iostream>
using namespace std;

int main() {
    int size = 8;
    int* array = new int[size];
    array[0] = 45;
    array[1] = 13;
    array[2] = 19;
    array[3] = 10001;
    array[4] = 25;
    array[5] = 555;
    array[6] = 38;
    array[7] = 667;

    heapsort(array, size);

    for (int i = 0; i < size; i++) {
        cout << "Elemento: " << array[i] << endl;
    }

    return 0;
}