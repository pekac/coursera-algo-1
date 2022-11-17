#include "deque.h"

#include<iostream>
using namespace std;


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