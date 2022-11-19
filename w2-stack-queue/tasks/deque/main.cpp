// #include "deque.h"

#include<iostream>
using namespace std;

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

template<class T>
TNode<T>::TNode(T val) {
    item = val;
    next = NULL;
}

template<class T>
TNode<T>::~TNode() {
    delete next;
}

template<class T>
void TNode<T>::linkNext(TNode *node) {
    next = node;
}

template<class T>
TNode<T>* TNode<T>::getNext() {
    return next;
}

template<class T>
T TNode<T>::getValue() {
    return item;
}

template<class T>
class Iterator {
    public:
        virtual bool hasNext() = 0;
        virtual T next() = 0;
};

template<class T>
class Iterable {
    public:
        virtual Iterator<T>* iterator() = 0;
};

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

template<class T>
DequeIterator<T>::DequeIterator(TNode<T>* first) {
    current = first;
}

template<class T>
DequeIterator<T>::~DequeIterator() {
    delete current;
}

template<class T>
bool DequeIterator<T>::hasNext() {
    return current != NULL;
}

template<class T>
T DequeIterator<T>::next() {
    T res = current->getValue();
    current = current->getNext();
    return res;
}

template<class T>
class Deque: public Iterable<T> {
    private:
        int count;
        TNode<T>* first;
        TNode<T>* last;
    public:
    // construct an empty deque
    Deque();
    
    ~Deque();

    // is the deque empty?
    bool isEmpty();

    // return the number of items on the deque
    int size();

    // add the item to the front
    void addFirst(T item);

    // add the item to the back
    void addLast(T item);

    // remove and return the item from the front
    T removeFirst();

    // remove and return the item from the back
    T removeLast();

    // return an iterator over items in order from front to back
    Iterator<T>* iterator();
};

template<class T>
Deque<T>::Deque() {
    first = NULL;
    last = NULL;
    count = 0;
}

template<class T>
Deque<T>::~Deque() {
    delete first;
    delete last;
}

template<class T>
bool Deque<T>::isEmpty() {
    return count == 0;
}

template<class T>
int Deque<T>::size() {
    return count;
}

template<class T>
void Deque<T>::addFirst(T item) {
    TNode<T> *old_first = first;
    first = new TNode<T>(item);
    first->linkNext(old_first);
    if (isEmpty()) {
        last = first;
    }
    count++;
}

template<class T>
void Deque<T>::addLast(T item) {
    if (isEmpty()) {
        return addFirst(item);
    }

    
    TNode<T> *old_last = last;
    last = new TNode<T>(item);
    old_last->linkNext(last);
    count++; 
}

template<class T>
T Deque<T>::removeFirst() {
    if (isEmpty()) {
        // throw e;
    }
    
    T res = first->getValue();
    first = first->getNext();
    count--;
    return res;
}

template<class T>
T Deque<T>::removeLast() {
    if (isEmpty()) {
        // throw e;
    }

    T res = last->getValue();
    if (first->getNext() == NULL) {
        first = last = NULL;
        count--;
        return res;
    }

    TNode<T>* nextToLast = first;
    while(nextToLast->getNext() != NULL && nextToLast->getNext()->getNext() != NULL) {
        nextToLast = nextToLast->getNext();
    }
    
    nextToLast->linkNext(NULL);
    last = nextToLast;
    count--;

    return res;
}

template<class T>
Iterator<T>* Deque<T>::iterator() {
    return new DequeIterator<T>(first);
}

int main() {
    Deque<int>* deq = new Deque<int>();
    deq->addFirst(4);
    deq->addFirst(5);
    deq->addFirst(6);
    deq->addFirst(7);
    deq->addLast(3);
    deq->addLast(2);
    deq->addLast(1);   
    
    deq->removeLast();
    int first = deq->removeFirst();
    int nextToLast = deq->removeLast();
    int size = deq->size();   
    cout << "Size: " << size << endl;

    Iterator<int>* iterator = deq->iterator();

    while (iterator->hasNext()) {
        int value = iterator->next();
        cout << "Iterator elemento: " << value << endl;
    }

    return 0;
}