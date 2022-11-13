#include "percolation.h"

Percolation::Percolation(int n) {
    size = n;
    uf = new QuickUnionWeighted(n * n + 2);
    openArray = new bool[n * n];

    int counter = 0;
    while (counter < n) {
        // first row to top node: n^2 node
        uf->unite(counter, n * n);

        // last row to bottom node: n^2 + 1
        uf->unite((n - 1) * n + counter, n * n + 1);
        
        counter++;
    }

    for (int i = 0; i < n * n; i++) {
        openArray[i] = false;
    }
}

Percolation::~Percolation() {
    delete uf; 
    delete[] openArray;
}

bool Percolation::checkIndex(int index) {
    return index >= 0 && index < size;
}

void Percolation::open(int row, int col) {
    if (!checkIndex(row) || !checkIndex(col)) {
        return;
    }

    int index = row * size + col;
    openArray[index] = true;
    openCount++;

    // left
    if (col > 0 && openArray[index - 1]) {
        uf->unite(index - 1, index);
    }
    // right
    if (col < size - 1 && openArray[index + 1]) {
        uf->unite(index, index + 1);
    }
    // top
    if (row > 0 && openArray[(row - 1) * size + col]) {
        uf->unite(index, (row - 1) * size + col);
    }
    // bottom
    if (row < size - 1 && openArray[(row + 1) * size + col]) {
        uf->unite(index, (row + 1) * size + col);
    }
}

bool Percolation::isOpen(int row, int col) {
    if (!checkIndex(row) || !checkIndex(col)) {
        return false;
    }

    return openArray[row * size + col];
}

bool Percolation::isFull(int row, int col) {
    if (!isOpen(row, col)) {
        return false;
    }

    return uf->connected(0, row * size + col);
}

int Percolation::numberOfOpenSites() {
    return openCount;
}

bool Percolation::percolates() {
    return uf->connected(size * size, size * size + 1);
}
