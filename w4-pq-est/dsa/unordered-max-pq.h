#ifndef UNORDERED_MAX_PQ_H
#define UNORDERED_MAX_PQ_H

class UnorderedMaxPQ {
    private:
        int n;
        int* array;
    public:
        UnorderedMaxPQ(int size);
        ~UnorderedMaxPQ();
        bool isEmpty();
        void insert(int item);
        int removeMax();
};

#endif