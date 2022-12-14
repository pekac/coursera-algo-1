#include "node.h"

#include <iostream>
using namespace std;

Node::Node(string item) {
    text = item;
    next = NULL;
}

Node::~Node() {
    delete next;
}

void Node::linkNext(Node *node) {
    next = node;
}

Node* Node::getNext() {
    return next;
}

string Node::getText() {
    return text;
}