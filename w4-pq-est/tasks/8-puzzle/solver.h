#ifndef SOLVER
#define SOLVER

#include "board.h"
#include "min-pq.h"

class Solver {
    private:
        int moves;
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
        // sequence of boards in a shortest solution; null if unsolvable
        // public Iterable<Board> solution()
};

#endif