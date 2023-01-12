#include "unordered-max-pq.h"

#include<iostream>
using namespace std;

/* lazy implementation, no checks, no resize */
UnorderedMaxPQ::UnorderedMaxPQ(int size) {
    n = 0;
    array = new int[size];
}

UnorderedMaxPQ::~UnorderedMaxPQ() {
    delete[] array;
}

bool UnorderedMaxPQ::isEmpty() {
    return n == 0;
}

void UnorderedMaxPQ::insert(int item) {
    array[n] = item;
    n++;
}

int UnorderedMaxPQ::removeMax() {
    int maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (array[i] > array[maxIndex]) {
            maxIndex = i;
        }
    }
    
    int max = array[maxIndex]; 
    array[maxIndex] = array[n - 1];
    array[n - 1] = max;  

    n--;
    return max;
}

