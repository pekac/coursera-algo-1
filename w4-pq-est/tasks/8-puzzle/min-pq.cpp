#include "min-pq.h"

#include<iostream>
using namespace std;

MinPQ::MinPQ() {
    n = 0;
}

MinPQ::~MinPQ() {
    array.clear();
    array.shrink_to_fit();
}

bool MinPQ::isEmpty() {
    return n == 0;
}

void MinPQ::insert(SearchNode* item) {
    array[n] = item;
    n++;
    swim(n - 1);
}

SearchNode* MinPQ::removeMin() {
    SearchNode* min = array[0];
    array[0] = array[n - 1];
    array[n - 1] = 0;
    n--;

    sink(0);

    return min;
}

void MinPQ::sink(int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left >= n) {
        return;
    }
    
    int swapIndex = right > n - 1 ? left : array[left]->priority() > array[right]->priority() ? left : right;

    if  (array[i] < array[swapIndex]) {
        SearchNode* temp = array[i];
        array[i] = array[swapIndex];
        array[swapIndex] = temp;

        sink(swapIndex);
    }
}

void MinPQ::swim(int i) {
    if (i == 0) {
        return;
    }
    
    int parentIndex = i % 2 == 0 ? (i - 2) / 2 : (i - 1) / 2;

    if (array[i]->priority() > array[parentIndex]->priority()) {
        SearchNode* temp = array[i];
        array[i] = array[parentIndex];
        array[parentIndex] = temp;

        swim(parentIndex);
    }
}