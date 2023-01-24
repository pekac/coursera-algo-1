#include "solver.h"

#include<iostream>

using std::cout;
using std::endl;

int main() {
    int n = 4;
    int** tiles = new int*[n];
    for (int i = 0; i < n; i++) {
        tiles[i] = new int[n];
    }
    
    tiles[0][0] = 3;
    tiles[0][1] = 6;
    tiles[0][2] = 8;

    tiles[1][0] = 7;
    tiles[1][1] = 1;
    tiles[1][2] = 5;

    tiles[2][0] = 4;
    tiles[2][1] = 2;
    tiles[2][2] = 0;

    // tiles[0][0] = 12;
    // tiles[0][1] = 5;
    // tiles[0][2] = 8;
    // tiles[0][3] = 10;

    // tiles[1][0] = 7;
    // tiles[1][1] = 11;
    // tiles[1][2] = 15;
    // tiles[1][3] = 13;

    // tiles[2][0] = 2;
    // tiles[2][1] = 14;
    // tiles[2][2] = 3;
    // tiles[2][3] = 4;

    // tiles[3][0] = 1;
    // tiles[3][1] = 9;
    // tiles[3][2] = 6;
    // tiles[3][3] = 0;

    Board* b = new Board(n, tiles);

    Solver* s = new Solver(b);

    int p = s->solve();

    cout << "Solved: " << p << endl;

    return 0;
}