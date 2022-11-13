#pragma once

#include<iostream>
using namespace std;

class Node {
    private:
        string text;     
        Node *next;

    public:
        Node(string item) {}

        ~Node() {}

        void linkNext(Node *node) {}

        Node* getNext() {}

        string getText() {}
};