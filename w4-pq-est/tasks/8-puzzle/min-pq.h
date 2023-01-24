#ifndef MIN_PQ_H
#define MIN_PQ_H

#include "search-node.h"
#include <vector>

using std::vector;

class MinPQ {
    private:
        int n;
        vector<SearchNode*> array;
        void sink(int i);
        void swim(int i);
    public:
        MinPQ();
        ~MinPQ();
        bool isEmpty();
        void insert(SearchNode* item);
        SearchNode* removeMin();
        void print();
};

#endif