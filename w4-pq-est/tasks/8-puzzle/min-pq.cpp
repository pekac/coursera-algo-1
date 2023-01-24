#include "min-pq.h"

#include<iostream>
using std::cout;
using std::endl;

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
    if (n >= array.size()) {
        array.push_back(item);
    } else {
        array[n] = item;
    }
    
    n++;
    swim(n - 1);
}

SearchNode* MinPQ::removeMin() {
    SearchNode* min = array[0];
    array[0] = array[n - 1];
    array[n - 1] = 0;
    n--;
    if (n == 0) {
        array.clear();
    }
    array.shrink_to_fit();

    sink(0);

    return min;
}

void MinPQ::sink(int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left >= n) {
        return;
    }
    
    int swapIndex = right > n - 1 ? left : array[left]->priority() < array[right]->priority() ? left : right;

    if  (array[i]->priority() > array[swapIndex]->priority()) {
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

    int firstPriority = array[i]->priority();
    int secondPriority = array[parentIndex]->priority();

    if (firstPriority < secondPriority) {
        SearchNode* temp = array[i];
        array[i] = array[parentIndex];
        array[parentIndex] = temp;

        swim(parentIndex);
    }
}

void MinPQ::print() {
    int i = 1;
    cout << "MIN PRIORITY QUEUE state: " << endl;
    for(SearchNode* item : array) {
        // Board* b = item->getBoard();
        // string str = b->toString();
        // cout << "Board: " << str << endl;
        // cout << "Moves: " << item->getMoves() << endl;
        cout << "Index: " << i << endl;
        cout << "Priority: " << item->priority() << endl;
        cout << "END" << endl << endl;
        i++;
    }
}