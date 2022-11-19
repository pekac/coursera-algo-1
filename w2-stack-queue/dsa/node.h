#ifndef NODE_H
#define NODE_H

class Node {
    private:
        string text;     
        Node *next;

    public:
        Node(string item);

        ~Node();

        void linkNext(Node *node);

        Node* getNext();

        string getText();
};

#endif