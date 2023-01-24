#ifndef SOLVER_H
#define SOLVER_H

#include <map>
#include "board.h"
#include "min-pq.h"

using std::map;

class Solver {
    private:
        int moves;
        map<string, bool> usedBoards;
        Board* initial;
        MinPQ* pqueue;
    public:
        Solver(Board* b);
        ~Solver();
        // is the initial board solvable? (see below)
        bool isSolvable();
        // min number of moves to solve initial board; -1 if unsolvable
        int minMoves();
        // find a solution to the initial board (using the A* algorithm)
        int solve();
        // add to used boards
        void addUsedBoard(string key);
        // check if board was already used
        bool alreadyUsed(string key);
        // sequence of boards in a shortest solution; null if unsolvable
        // public Iterable<Board> solution()
};

#endif