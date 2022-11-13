template<class T>
class TNode {
    private:
        T item;     
        TNode *next;
    public:
        TNode(T val) {}

        ~TNode() {}

        void linkNext(TNode *node) {}

        TNode* getNext() {}

        T getValue() {}
};