#pragma once

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