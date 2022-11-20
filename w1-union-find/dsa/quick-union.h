#ifndef QUICK_UNION_H
#define QUICK_UNION_H

class QuickUnion {
    private:
        int *ids;
        int length = 0;
    public:
        QuickUnion(int n);
        
        ~QuickUnion();

        int root(int a); 

        void unite(int a, int b);

        bool connected(int a, int b);
};

#endif