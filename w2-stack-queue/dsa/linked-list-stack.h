#ifndef LINKED_LIST_STACK_H
#define LINKED_LIST_STACK_H

class LinkedListStack {
    private:
        Node* first;
    public: 
        LinkedListStack();

        ~LinkedListStack();

        bool isEmpty();

        void push(string text);

        string pop();
};

#endif