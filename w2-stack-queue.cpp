#include<iostream>
using namespace std;

class Node {
    private:
        string text;     
        Node *next;

    public:
        Node(string item) {
            text = item;
            next = NULL;
        }

        void linkNext(Node *node) {
            next = node;
        }

        Node* getNext() {
            return next;
        }

        string getText() {
            return text;
        }
};

class LinkedListStack {
    private:
        Node* first = NULL;
    public: 
        bool isEmpty() {
            return first == NULL;
        }        

        void push(string text) {
            Node *old_first = first;
            first = new Node(text);
            first->linkNext(old_first);
        }

        string pop() {
            string res = first->getText();
            first = first->getNext();
            return res;
        }
};

class FixedCapacityStack {
    private:
        string *stack;
        int count; 
    public:
        FixedCapacityStack(int n) {
            stack = new string[n];
            count = 0;
        }

        bool isEmpty() {
            return count == 0;
        }

        void push(string text) {
            stack[count] = text;
            count++;
        }

        string pop() {
            if (count < 1) {
                return "";
            }

            return stack[--count];
        }
};

class LinkedListQueue {
    private:
        Node* first;
        Node* last;
    public:
        LinkedListQueue() {
            first = NULL;
            last = NULL;
        }

        bool isEmpty() {
            return first == NULL;
        }
    
        void enqueue(string text) {
            if (isEmpty()) {
                first = last = new Node(text);
                return;
            }

            Node* old_last = last;
            last = new Node(text);
            old_last->linkNext(last);
        }

        string dequeue() {
            if (isEmpty()) {
                return "";
            }

            string res = first->getText();
            first = first->getNext();
            return res;
        }
};

// generic node + stack
template<class T>
class TNode {
    private:
        T item;     
        TNode *next;

    public:
        TNode(T val) {
            item = val;
            next = NULL;
        }

        void linkNext(TNode *node) {
            next = node;
        }

        TNode* getNext() {
            return next;
        }

        T getValue() {
            return item;
        }
};


template<class T>
class Stack {
    private:
        TNode<T>* first;
    public: 
        Stack() {
            first = NULL;
        }

        bool isEmpty() {
            return first == NULL;
        }        

        void push(T val) {
            TNode<T> *old_first = first;
            first = new TNode<T>(val);
            first->linkNext(old_first);
        }

        T pop() {
            T res = first->getValue();
            first = first->getNext();
            return res;
        }
};

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
        DequeIterator(TNode<T>* first) {
            current = first;
        }

        bool hasNext() {
            return current != NULL;
        }

        T next() {
            T res = current->getValue();
            current = current->getNext();
            return res;
        }
};

template<class T>
class Deque: public Iterable<T> {
    private:
        int count;
        TNode<T>* first;
        TNode<T>* last;
    public:
    // construct an empty deque
    Deque() {
        first = NULL;
        last = NULL;
        count = 0;
    }

    // is the deque empty?
    bool isEmpty() {
        return count == 0;
    }

    // return the number of items on the deque
    int size() {
        return count;
    }

    // add the item to the front
    void addFirst(T item) {
        TNode<T> *old_first = first;
        first = new TNode<T>(item);
        first->linkNext(old_first);
        if (isEmpty()) {
            last = first;
        }
        count++;
    }

    // add the item to the back
    void addLast(T item) {
        if (isEmpty()) {
            return addFirst(item);
        }

        
        TNode<T> *old_last = last;
        last = new TNode<T>(item);
        old_last->linkNext(last);
        count++; 
    }

    // remove and return the item from the front
    T removeFirst() {
        if (isEmpty()) {
            // throw e;
        }

        T res = first->getValue();
        first = first->getNext();
        count--;
        return res;
    }

    // remove and return the item from the back
    // keep prev ref?
    T removeLast() {
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

    // return an iterator over items in order from front to back
    Iterator<T>* iterator() {
        return new DequeIterator<T>(first);
    }
};


int main() {
    Stack<int>* s = new Stack<int>();
    s->push(5);
    s->push(17);
    s->push(43);

    s->pop();
    int p = s->pop();

    cout << "Second stack el: " << p << endl;

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

    cout << "First elemento: " << first << endl;
    cout << "Next to last elemento: " << nextToLast << endl;
    cout << "Deque size: " << size << endl;

    Iterator<int>* iterator = deq->iterator();

    while (iterator->hasNext()) {
        int next = iterator->next();
        cout << "Iterator elemento: " << next << endl;
    }

    return 0;
}