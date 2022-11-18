#include "quick-union.h"

QuickUnion::QuickUnion(int n) {
    length = n;
    ids = new int[n];
    for (int i = 0; i < n; i++) {
        ids[i] = i;
    }
}

QuickUnion::~QuickUnion() {
    delete[] ids;
}

int QuickUnion::root(int a) {
    if (ids[a] == a) {
        return a;
    }

    return root(ids[a]);
} 

void QuickUnion::unite(int a, int b) {
    int root_a = root(a);
    ids[root_a] = root(b);
}

bool QuickUnion::connected(int a, int b) {
    return root(a) == root(b);
}