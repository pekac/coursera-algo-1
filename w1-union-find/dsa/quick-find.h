#ifndef QUICK_FIND_H
#define QUICK_FIND_H

class QuickFind {
    private:
        int *ids;
        int length = 0;
    public:
        QuickFind(int n);

        ~QuickFind();
        
        void unite(int a, int b);

        bool connected(int a, int b);
};

#endif