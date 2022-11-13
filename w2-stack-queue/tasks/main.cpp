#pragma once

#include "../algos/generic-stack.h"
#include "deque.h"

#include<iostream>
using namespace std;

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