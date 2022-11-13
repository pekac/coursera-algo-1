#include "percolation.h"
#include<iostream>

using namespace std;

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