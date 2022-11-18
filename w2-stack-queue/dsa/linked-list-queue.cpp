#include "linked-list-queue.h"

LinkedListQueue::LinkedListQueue() {
    first = NULL;
    last = NULL;
}

LinkedListQueue::LinkedListQueue() {
    delete first;
    delete last;
}

bool LinkedListQueue::isEmpty() {
    return first == NULL;
}

void LinkedListQueue::enqueue(string text) {
    if (isEmpty()) {
        first = last = new Node(text);
        return;
    }

    Node* old_last = last;
    last = new Node(text);
    old_last->linkNext(last);
}

string LinkedListQueue::dequeue() {
    if (isEmpty()) {
        return "";
    }

    string res = first->getText();
    first = first->getNext();
    return res;
}