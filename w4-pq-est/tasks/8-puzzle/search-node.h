#ifndef SEARCH_NODE
#define SEARCH_NODE

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
        Board* getBoard();
        Board* getPreviousBoard();
};

#endif