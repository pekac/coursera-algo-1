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
    usedBoards.clear();
};

bool Solver::isSolvable() {
    return false;
};

int Solver::minMoves() {
    return isSolvable() ? moves : -1;
};

bool Solver::alreadyUsed(string key) {
    if (usedBoards[key]) {
        return true;
    }

    return false;
}

void Solver::addUsedBoard(string key) {
    if (!alreadyUsed(key)) {
        usedBoards[key] = true;
    }
}

int Solver::solve() {
    if (pqueue->isEmpty()) {
        return -1;   
    }

    // pqueue->print();

    SearchNode* first = pqueue->removeMin();
    
    Board* board = first->getBoard();
    addUsedBoard(board->getKey());
    
    Board* prevBoard = NULL;

    if (first->getMoves() > 0) {
        prevBoard = first->getPreviousBoard();
    }

    if (board->isGoal()) {
        return 1;
    }

    vector<Board*> neighbors = board->neighbors();
    for(Board* item : neighbors) {
        string key = item->getKey();
        if (!alreadyUsed(key)) {
            addUsedBoard(key);
            SearchNode* node = new SearchNode(item, first->getMoves() + 1, first);
            pqueue->insert(node);
        }
    }

    return solve();
};