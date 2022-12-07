#include "quick-select.h"
#include "quicksort.h"
#include <bits/stdc++.h>

#include<iostream>
using namespace std;

int select(int* array, int size, int k) {
    shuffle(array, array + size, default_random_engine(0));
    int lo = 0;
    int hi = size - 1;
    while (hi > lo) {
        int j = partition(array, lo, hi);
        if (j < k) {
            lo = j + 1;
        }
        else if (j > k) {
            hi = j - 1;
        }
        else {
            return array[k];
        }
    }
    return array[k];
}
   