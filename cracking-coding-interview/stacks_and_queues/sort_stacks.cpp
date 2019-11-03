// Copyright 2019, Kartik Madhira

#include "stack.h"

template<typename T>
void sort(Stack<T> *stack) {
    Stack<T> *temp_stack = new Stack<T>();
    T temp_var;
    int unsorted_len = stack->get_length();
    while(unsorted_len > 0) {
        temp_var = stack->pop();
        int curr_len = 0;
        while (curr_len < unsorted_len - 1) {
            if (temp_var > stack->peek()) {
                temp_stack->push(stack->pop());
            } else {
                temp_stack->push(temp_var);
                temp_var = stack->pop();
            }
            curr_len++;
        }
        stack->push(temp_var);
        while (!temp_stack->is_empty()) {
            stack->push(temp_stack->pop());
        }
        unsorted_len--;
    }
    delete temp_stack;
}


int main() {
    Stack<int> *stack = new Stack<int>();
    stack->push(45);
    stack->push(4);
    stack->push(224);
    stack->push(2);
    stack->push(568);

    sort(stack);
    // stack.peek)
    cout << stack->pop() << "\n";
    cout << stack->pop() << "\n";
    cout << stack->pop() << "\n";
    cout << stack->pop() << "\n";
    cout << stack->pop() << "\n";

}