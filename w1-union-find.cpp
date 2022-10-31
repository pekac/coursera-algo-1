#include<iostream>
using namespace std;

class QuickFind {
    private:
        int *ids;
        int length = 0;
    public:
        QuickFind(int N) { 
            length = N;
            ids = new int[N];
            for (int i = 0; i < N; i++) {
                ids[i] = i;
            }
        }

        void unite(int a, int b) {
            if (!connected(a, b)) {
                for (int i = 0; i < length; i++) {
                    if (ids[i] == ids[a]) {
                        ids[i] = ids[b];
                    }
                }
            }
        }

        bool connected(int a, int b) {
            return ids[a] == ids[b];
        }
};

class QuickUnion {
    private:
        int *ids;
        int length = 0;
    public:
        QuickUnion(int N) {
            length = N;
            ids = new int[N];
            for (int i = 0; i < N; i++) {
                ids[i] = i;
            }
        }

        int root(int a) {
            if (ids[a] == a) {
                return a;
            }

            return root(ids[a]);
        } 

        void unite(int a, int b) {
            int root_a = root(a);
            ids[root_a] = root(b);
        }

        bool connected(int a, int b) {
            return root(a) == root(b);
        }
};

class QuickUnionWeighted {
    private:
        int *ids;
        int *size;
        int length = 0;
    public:
        QuickUnionWeighted(int N) {
            length = N;
            ids = new int[N];
            size = new int[N];
            for (int i = 0; i < N; i++) {
                ids[i] = i;
                size[i] = 1;
            }
        }

        int inline root(int a) {
            if (ids[a] == a) {
                return a;
            }

            ids[a] = ids[ids[a]]; // path compression
            return root(ids[a]);
        } 

        void unite(int a, int b) {
            int root_a = root(a);
            int root_b = root(b);
            
            if (root_a == root_b) {
                return;
            } 

            if (size[root_a] <= size[root_b]) {
                ids[root_a] = root_b;
                size[root_b] += size[root_a];
            } else {
                ids[root_b] = root_a;
                size[root_a] += size[root_b];
            }
        }

        bool connected(int a, int b) {
            return root(a) == root(b);
        }
};

class Percolation {
    private:
        int size = 0;
        int openCount = 0;
        bool *openArray;
        QuickUnionWeighted *uf;
    public:
        Percolation(int n) {
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

        bool checkIndex(int index) {
            return index >= 0 && index < size;
        }

        void open(int row, int col) {
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

        bool isOpen(int row, int col) {
            if (!checkIndex(row) || !checkIndex(col)) {
                return false;
            }

            return openArray[row * size + col];
        }

        bool isFull(int row, int col) {
            if (!isOpen(row, col)) {
                return false;
            }

            return uf->connected(0, row * size + col);
        }

        int numberOfOpenSites() {
            return openCount;
        }

        bool percolates() {
            return uf->connected(size * size, size * size + 1);
        }
};

int main() {
    int p_size = 5;
    Percolation *p = new Percolation(p_size);
    p->open(0, 2);
    p->open(1, 2);
    p->open(1, 1);
    p->open(2, 1);
    p->open(3, 1);
    p->open(3, 2);
    p->open(3, 3);
    p->open(4, 3);
    cout << "First system percolates: " << p->percolates() << endl;

    int chess_size = 33000;
    Percolation *chess_p = new Percolation(chess_size); // ~10^9 elements
    for (int i = 0; i < chess_size; i++) {
        for (int j = 0; j < chess_size; j++) {
            if ((i + j) % 2 == 0) {
                chess_p->open(i, j);
            }
        }
    }
    cout << "Second system percolates: " << chess_p->percolates() << endl;

    return 0;
}