#include "randomized-queue.h"
#include "../../dsa/iterator.h"

#include<iostream>
using namespace std;

int main() {
    RandomizedQueue<int>* queue = new RandomizedQueue<int>(3);
    queue->enqueue(7);
    queue->enqueue(6);
    queue->enqueue(5);
    queue->enqueue(4);
    queue->enqueue(3);
    queue->enqueue(2);
    queue->enqueue(1);
    queue->enqueue(0);

    Iterator<int>* iterator = queue->iterator();
    while (iterator->hasNext()) {
        int value = iterator->next();
        cout << "Iterator elemento: " << value << endl;
    }
    cout << "Iterator end" << endl;

    cout << "Iterator2 end" << endl;

    int a = queue->dequeue();
    cout << "Value removed a: " << a << endl;

    int b = queue->dequeue();
    cout << "Value removed b: " << b << endl;

    int s = queue->sample();
    cout << "Sample s: " << s << endl;

    int c = queue->dequeue();
    cout << "Value removed c: " << c << endl;

    int d = queue->dequeue();
    cout << "Value removed d: " << d << endl;

    int e = queue->dequeue();
    cout << "Value removed e: " << e << endl;
    
    int f = queue->dequeue();
    cout << "Value removed f: " << f << endl;

    Iterator<int>* iterator2 = queue->iterator();
    while (iterator2->hasNext()) {
        int value = iterator2->next();
        cout << "Iterator2 elemento: " << value << endl;
    }
    cout << "Iterator2 end" << endl;

    return 0;
}