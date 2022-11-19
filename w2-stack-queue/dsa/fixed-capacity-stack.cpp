#include "fixed-capacity-stack.h"

#include <iostream>
using namespace std;

FixedCapacityStack::FixedCapacityStack(int n) {
    stack = new string[n];
    count = 0;
}

FixedCapacityStack::~FixedCapacityStack() {
    delete[] stack;
}

bool FixedCapacityStack::isEmpty() {
    return count == 0;
}

void FixedCapacityStack::push(string text) {
    stack[count] = text;
    count++;
}

string FixedCapacityStack::pop() {
    if (count < 1) {
        return "";
    }

    return stack[--count];
}