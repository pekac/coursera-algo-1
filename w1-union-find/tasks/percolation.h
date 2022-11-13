#pragma once

#include "../algos/quick-union-weighted.h"

class Percolation {
    private:
        int size = 0;
        int openCount = 0;
        bool *openArray;
        QuickUnionWeighted *uf;
    public:
        Percolation(int n) {}
        
        ~Percolation() {}

        bool checkIndex(int index) {}

        void open(int row, int col) {}

        bool isOpen(int row, int col) {}

        bool isFull(int row, int col) {}

        int numberOfOpenSites() {}

        bool percolates() {}
};
