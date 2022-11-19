#ifndef GENERIC_NODE_H
#define GENERIC_NODE_H

template<class T>
class TNode {
    private:
        T item;     
        TNode<T>* next;
    public:
        TNode(T val);

        ~TNode();

        void linkNext(TNode<T>* node);

        TNode<T>* getNext();

        T getValue();
};

#endif