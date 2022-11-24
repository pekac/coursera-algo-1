#include "randomized-queue.h"
#include "../../dsa/iterator.h"

#include<iostream>
using namespace std;

int main() {
    RandomizedQueue<int>* queue = new RandomizedQueue<int>(3);
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


    return 0;
}