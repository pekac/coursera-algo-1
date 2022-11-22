#include "node.h"
#include "linked-list-stack.h"

#include <iostream>
using namespace std;

LinkedListStack::LinkedListStack() {
    first = NULL;
}

LinkedListStack::~LinkedListStack() {
    delete first;
}

bool LinkedListStack::isEmpty() {
    return first == NULL;
}        

void LinkedListStack::push(string text) {
    Node *oldFirst = first;
    first = new Node(text);
    first->linkNext(oldFirst);
}

string LinkedListStack::pop() {
    string res = first->getText();
    first = first->getNext();
    return res;
}