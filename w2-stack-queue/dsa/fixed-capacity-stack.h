#ifndef FIXED_CAPACITY_STACK_H
#define FIXED_CAPACITY_STACK_H

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

#endif