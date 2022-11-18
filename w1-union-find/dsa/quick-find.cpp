#include "quick-find.h"

QuickFind::QuickFind(int n) { 
    length = n;
    ids = new int[n];
    for (int i = 0; i < n; i++) {
        ids[i] = i;
    }
}

QuickFind::~QuickFind() { 
    delete[] ids;
}

void QuickFind::unite(int a, int b) {
    if (!connected(a, b)) {
        for (int i = 0; i < length; i++) {
            if (ids[i] == ids[a]) {
                ids[i] = ids[b];
            }
        }
    }
}

bool QuickFind::connected(int a, int b) {
    return ids[a] == ids[b];
}