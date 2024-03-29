#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Board {
    private:
        int n;
        int emptyI;
        int emptyJ;
        int** tiles;
        int priority;
        int totalManhattan;
        string key;
    public:
        // create a board from an n-by-n array of tiles,
        Board(int size, int** board);

        // destructor
        ~Board();

        // string representation of this board
        string toString();

        // board dimension n
        int dimension();

        // number of tiles out of place
        int hamming();

        // sum of Manhattan distances between tiles and goal
        int manhattan();

        // get priority
        int getPriority();

        // get key
        string getKey();

        // is this board the goal board?
        bool isGoal();

        // does this board equal b
        bool equals(Board* b);  

        // all neighboring boards
        vector<Board*> neighbors();

        Board* createNeighbor(int swapI, int swapJ);

        // a board that is obtained by exchanging any pair of tiles
        // Board twin();
};

#endif