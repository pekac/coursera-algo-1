#ifndef HEAP_MAX_PQ_H
#define HEAP_MAX_PQ_H

class HeapMaxPQ {
    private:
        int n;
        int* array;
        void sink(int i);
        void swim(int i);
    public:
        HeapMaxPQ(int size);
        ~HeapMaxPQ();
        bool isEmpty();
        void insert(int item);
        int removeMax();
};

#endif