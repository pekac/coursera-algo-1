#include "board.h"
#include <cmath>
#include <vector>

using std::abs;
using std::to_string;
using std::vector;

Board::Board(int size, int** board) {
    n = size;
    tiles = new int*[n];
    for (int i = 0; i < n; i++) {
        tiles[i] = new int[n];
        for (int j = 0; j < n; j++) {
            tiles[i][j] = board[i][j];
            if (tiles[i][j] == 0) {
                emptyI = i;
                emptyJ = j;
            }
        }   
    }
}

Board::~Board() {
    for (int i = 0; i < n; i++) {
        delete[] tiles[i];
    }

    delete[] tiles;
}

string Board::toString() {
    string str = to_string(n) + "\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            str += to_string(tiles[i][j]) + " ";
        }
        str += to_string(tiles[i][n - 1]) + "\n";
    }
    return str;
}

int Board::dimension() {
    return n;
}

int Board::hamming() {
    int misplaced = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (tiles[i][j] != i * n + j + 1) {
                misplaced++;
            }
        }
    }
    // zero will always be "misplaced"
    return misplaced - 1;
}

int Board::manhattan() {
    int totalManhattan = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (tiles[i][j] == 0) {
                continue;
            }

            int val = tiles[i][j];

            int goalI = val % n == 0 ? val / n - 1 : val % n;
            int goalJ = val - (goalI * n + 1);

            totalManhattan += abs(goalI - i) + abs(goalJ - j);
        }
    }
    return totalManhattan;
}

bool Board::isGoal() {
    return hamming() == 0;
}

bool Board::equals(Board* b) {
    if (b == NULL || n != b->dimension()) {
        return false;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (tiles[i][j] != b->tiles[i][j]) {
                return false;
            }
        }
    }

    return true;
}

void Board::updateEmpty(int i, int j) {
    emptyI = i;
    emptyJ = j;
};

Board* Board::createNeighbor(int swapI, int swapJ) {
    Board* b = new Board(n, tiles);
    int temp = b->tiles[swapI][swapJ];
    b->tiles[swapI][swapJ] = b->tiles[emptyI][emptyJ];
    b->tiles[emptyI][emptyJ] = temp;
    b->updateEmpty(swapI, swapJ);
    return b;
}

vector<Board*> Board::neighbors() {
    vector<Board*> neighbors;

    // top 
    if (emptyI > 0) {
        Board* b = createNeighbor(emptyI - 1, emptyJ);
        neighbors.push_back(b);
    }

    // bottom
    if (emptyI < n - 1) {
        Board* b = createNeighbor(emptyI + 1, emptyJ);
        neighbors.push_back(b);
    }

    // left
    if (emptyJ > 0) {
        Board* b = createNeighbor(emptyI, emptyJ - 1);
        neighbors.push_back(b);
    }

    // right
    if (emptyJ < n - 1) {
        Board* b = createNeighbor(emptyI, emptyJ + 1);
        neighbors.push_back(b);
    }

    return neighbors;
}

