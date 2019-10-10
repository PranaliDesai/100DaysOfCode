// Copyright 2019 Kartik Madhira
// An implementation of stack class - Last in, First Out(LIFO)
#pragma once
#include <iostream>

using std::cout;
using std::endl;
template <typename T>
class StackNode {
    public:
    T data;
    StackNode *next;
    StackNode(T node) {
        this->data = node;
        this->next = nullptr;
    }
};

template <typename T>
class Stack {
public:
    // push, pop, peek, isempty
    Stack();
    T pop();
    void push(T node);
    T peek();
    bool is_empty();
    void print_stack();
    ~Stack();
private:
    StackNode<T> *top;
    int length;
};

template<typename T>
Stack<T>::Stack() {
    top = nullptr;
    length = 0;
}

template<typename T>
void Stack<T>::print_stack() {
    int len_copy = length;
    StackNode<T> *temp = top;
    while (len_copy > 0) {
        cout << temp->data << endl;
        temp = temp->next;
        len_copy--;
    }
}


template<typename T>
bool Stack<T>::is_empty() {
    if (top == nullptr) {
        return true;
    }
    return false;
}

template <typename T>
T Stack<T>::pop() {
    if (is_empty()) {
        StackNode<T> *temp = top;
        delete top;
        StackNode<T> top = new StackNode<T>(temp->data);
        return top->data;
    }
    return nullptr;
}

template<typename T>
void Stack<T>::push(T node) {
    if (is_empty()) {
        top = new StackNode<T>(node);
    } else {

        StackNode<T> *new_node = new StackNode<T>(node);
        StackNode<T> *temp = top;
        top = new_node;
        top->next = temp;
    }
    length++;
}

template<typename T>
T Stack<T>::peek() {
    return top->data;
}

template<typename T>
Stack<T>::~Stack() {

    while (length > 0) {
        StackNode<T> *temp = top;
        delete top;
        StackNode<T> *top = temp;
        length--;
    }
}
