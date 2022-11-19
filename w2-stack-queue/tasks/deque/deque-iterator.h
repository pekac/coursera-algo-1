#ifndef DEQUE_ITERATOR_H
#define DEQUE_ITERATOR_H

template<class T>
class DequeIterator: public Iterator<T> {
    private:
        TNode<T>* current;
    public:
        DequeIterator(TNode<T>* first);

        ~DequeIterator();

        bool hasNext();

        T next();
};

#endif