#include "solver.h"

Solver::Solver(Board* b) {
    initial = b;
    pqueue = new MinPQ();

    SearchNode* node = new SearchNode(b, 0, NULL);
    pqueue->insert(node);
};

Solver::~Solver() {
    delete initial;
    delete pqueue;
};

bool Solver::isSolvable() {

};

int Solver::minMoves() {
    return isSolvable() ? moves : -1;
};

int Solver::solve() {
    if (pqueue->isEmpty()) {
        return -1;   
    }

    SearchNode* first = pqueue->removeMin();
    Board* board = first->getBoard();
    Board* prevBoard = first->getPreviousBoard();
    if (board->isGoal()) {
        return 1;
    }

    vector<Board*> neighbors = board->neighbors();
    for(Board* item : neighbors) {
        if (!item->equals(prevBoard)) {
            SearchNode* node = new SearchNode(item, moves + 1, first);
            pqueue->insert(node);
        }
    }

    solve();
};