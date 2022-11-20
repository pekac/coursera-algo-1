#ifndef QUICK_UNION_WEIGHTED_H
#define QUICK_UNION_WEIGHTED_H

class QuickUnionWeighted {
    private:
        int *ids;
        int *size;
        int length = 0;
    public:
        QuickUnionWeighted(int n);
        
        ~QuickUnionWeighted();
        
        int root(int a); 

        void unite(int a, int b);

        bool connected(int a, int b);
};

#endif