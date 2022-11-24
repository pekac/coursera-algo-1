#include "randomized-queue.h"
#include "rnd-queue-iterator.h"
#include "time.h"
#include <cstddef>
#include <cstdlib>

template<class T>
RandomizedQueue<T>::RandomizedQueue(int size) {
    srand(time(0));
    n = 0;
    capacity = size;
    array = new T[size];
}

template<class T>
RandomizedQueue<T>::~RandomizedQueue() {
    delete[] array;
}

template<class T>
bool RandomizedQueue<T>::isEmpty() {
    return n == 0;
}

template<class T>
int RandomizedQueue<T>::size() {
    return n;
}

template<class T>
void RandomizedQueue<T>::resize(int size) {
    capacity = size;
    T* resizedArray = new T[capacity];
    for (int i = 0; i < n; i++) {
        resizedArray[i] = array[i];
    }
    array = resizedArray;
}

template<class T>
void RandomizedQueue<T>::enqueue(T item) {
    if (n == capacity) {
        resize(capacity * 2);
    }
    array[n] = item;
    n++;
}

template<class T>
T RandomizedQueue<T>::dequeue() {
    if (isEmpty()) {
        /* Throw e */
    }
    
    int index = rand() % n;
    /* swap index with last */
    T removeItem = array[index];
    array[index] = array[n - 1];
    array[n - 1] = removeItem;
    /* remove last */
    n--;
    return removeItem;
}

template<class T>
T RandomizedQueue<T>::sample() {
    if (isEmpty()) {
        /* Throw e */
    }
    
    int index = rand() % n;
    return array[index];
}

template<class T>
Iterator<T>* RandomizedQueue<T>::iterator() {
    /* shuffle the queue and return from first to last */
    return new RndQuequeIterator<T>(array, n);
}
 
template class RandomizedQueue<int>;