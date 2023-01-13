#include "heap-max-pq.h"

#include<iostream>
using namespace std;

int main() {
    HeapMaxPQ* hpq = new HeapMaxPQ(10);
    hpq->insert(24);
    hpq->insert(13);
    hpq->insert(61);
    hpq->insert(17);
    hpq->insert(7);
    hpq->insert(11);
    hpq->insert(45);
    hpq->insert(5);
    hpq->insert(29);

    for (int i = 0; i < 9; i++) {
        int max = hpq->removeMax();
        cout << "Max elemento: " << max << endl;
    } 

    return 0;
}