#ifndef LINKED_LIST_QUEUE_H
#define LINKED_LIST_QUEUE_H

class LinkedListQueue {
    private:
        Node* first;
        Node* last;
    public:
        LinkedListQueue();

        ~LinkedListQueue();

        bool isEmpty();
    
        void enqueue(string text);

        string dequeue();
};

#endif