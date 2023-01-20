#include "board.h"
#include <cmath>

using std::abs;
using std::to_string;

Board::Board(int size, int** board) {
    n = size;
    for (int i = 0; i < n; i++) {
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
            str += tiles[i][j] + " ";
        }
        str += tiles[i][n - 1] + "\n";
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
    return manhattan() + hamming() == 0;
}

bool Board::equals(Board* b) {
    if (n != b->dimension()) {
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

Iterator<Board>* Board::iterator() {

}

