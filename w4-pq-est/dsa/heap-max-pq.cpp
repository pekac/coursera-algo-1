#include "heap-max-pq.h"

#include<iostream>
using namespace std;

HeapMaxPQ::HeapMaxPQ(int size) {
    n = 0;
    array = new int[size];
}

HeapMaxPQ::~HeapMaxPQ() {
    delete[] array;
}

bool HeapMaxPQ::isEmpty() {
    return n == 0;
}

void HeapMaxPQ::insert(int item) {
    array[n] = item;
    n++;
    swim(n - 1);
}

int HeapMaxPQ::removeMax() {
    int max = array[0];
    array[0] = array[n - 1];
    array[n - 1] = 0;
    n--;

    sink(0);

    return max;
}

void HeapMaxPQ::sink(int i) {
    if (i >= n - 2) {
        return;
    }

    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int swapIndex = array[left] > array[right] ? left : right;

    if  (array[i] < array[swapIndex]) {
        int temp = array[i];
        array[i] = array[swapIndex];
        array[swapIndex] = temp;

        sink(swapIndex);
    }
}

void HeapMaxPQ::swim(int i) {
    if (i == 0) {
        return;
    }
    
    int parentIndex = i % 2 == 0 ? (i - 2) / 2 : (i - 1) / 2;

    if (array[i] > array[parentIndex]) {
        int temp = array[i];
        array[i] = array[parentIndex];
        array[parentIndex] = temp;

        swim(parentIndex);
    }
}