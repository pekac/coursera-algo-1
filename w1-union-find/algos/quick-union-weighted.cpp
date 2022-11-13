#include "quick-union-weighted.h"

QuickUnionWeighted::QuickUnionWeighted(int n) {
    length = n;
    ids = new int[n];
    size = new int[n];
    for (int i = 0; i < n; i++) {
        ids[i] = i;
        size[i] = 1;
    }
}

QuickUnionWeighted::~QuickUnionWeighted() {
    delete[] ids;
    delete[] size;
}

int QuickUnionWeighted::root(int a) {
    if (ids[a] == a) {
        return a;
    }

    ids[a] = ids[ids[a]]; // path compression
    return root(ids[a]);
} 

void QuickUnionWeighted::unite(int a, int b) {
    int root_a = root(a);
    int root_b = root(b);
    
    if (root_a == root_b) {
        return;
    } 

    if (size[root_a] <= size[root_b]) {
        ids[root_a] = root_b;
        size[root_b] += size[root_a];
    } else {
        ids[root_b] = root_a;
        size[root_a] += size[root_b];
    }
}

bool QuickUnionWeighted::connected(int a, int b) {
    return root(a) == root(b);
}