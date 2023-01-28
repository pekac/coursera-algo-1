#ifndef SEARCH_NODE_H
#define SEARCH_NODE_H

#include "board.h"

class SearchNode {
    private:
        int moves;
        SearchNode* prev;
        Board* b;
    public:
        SearchNode(Board* b, int moves, SearchNode* prev);
        ~SearchNode();
        int priority();
        int getMoves();
        Board* getBoard();
        Board* getPreviousBoard();
};

#endif