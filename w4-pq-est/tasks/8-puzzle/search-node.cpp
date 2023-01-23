#include "search-node.h"

SearchNode::SearchNode(Board* x, int n, SearchNode* previous) {
    b = x;
    moves = n;
    prev = previous;
}

SearchNode::~SearchNode() {
    delete b;
    delete prev;
}

int SearchNode::priority() {
    return b->hamming() + moves;
}