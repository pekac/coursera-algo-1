#include "search-node.h"

using std::cout;
using std::endl;

SearchNode::SearchNode(Board* x, int n, SearchNode* previous) {
    b = x;
    moves = n;
    prev = previous;
}

SearchNode::~SearchNode() {
    delete b;
    delete prev;
}

int SearchNode::getMoves() {
    return moves;
}

int SearchNode::priority() {
    return b->getPriority() + moves;
}

Board* SearchNode::getBoard() {
    return b;
}

Board* SearchNode::getPreviousBoard() {
    return prev->getBoard();
}
