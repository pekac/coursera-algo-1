#include "linked-list-stack.h"

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
    Node *old_first = first;
    first = new Node(text);
    first->linkNext(old_first);
}

string LinkedListStack::pop() {
    string res = first->getText();
    first = first->getNext();
    return res;
}