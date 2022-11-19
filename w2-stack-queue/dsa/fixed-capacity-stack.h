class FixedCapacityStack {
    private:
        string *stack;
        int count; 
    public:
        FixedCapacityStack(int n);

        ~FixedCapacityStack();

        bool isEmpty();

        void push(string text);

        string pop();
};