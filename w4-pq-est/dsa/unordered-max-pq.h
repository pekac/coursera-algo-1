#ifndef UNORDERED_MAX_PQ
#define UNORDERED_MAX_PQ

class UnorderedMaxPQ {
    private:
        int n;
        int* array;
    public:
        UnorderedMaxPQ(int size);

        ~UnorderedMaxPQ();

        bool isEmpty();

        void insert(int item);

        int removeMax();
};

#endif