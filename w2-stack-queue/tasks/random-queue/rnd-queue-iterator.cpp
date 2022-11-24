#include "rnd-queue-iterator.h"
#include <bits/stdc++.h>

#include<iostream>
using namespace std;

template<class T>
T* RndQuequeIterator<T>::shuffleArray(T* array, int size) {
    shuffle(array, array + size, default_random_engine(0));
    return array;
}

template<class T>
RndQuequeIterator<T>::RndQuequeIterator(T* array, int size) {
    index = 0;
    n = size;
    randomArray = shuffleArray(array, size);
}

template<class T>
RndQuequeIterator<T>::~RndQuequeIterator() {
    delete[] randomArray;
}

template<class T>
bool RndQuequeIterator<T>::hasNext() {
    return index < n;
}

template<class T>
T RndQuequeIterator<T>::next() {
    T res = randomArray[index];
    index++;
    return res;
}

/* undefined ref fix - not sure if valid */
template class RndQuequeIterator<int>;