// Copyright 2019 Kartik Madhira

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
    T pop_min();
    void push(T node);
    T peek();
    bool is_empty();
    void print_stack();
    void min_stack(T node);
    ~Stack();
private:
    StackNode<T> *top;
    StackNode<T> *top_min;
    int length;
    int curr_min;
};

template<typename T>
Stack<T>::Stack() {
    top = nullptr;
    top_min = nullptr;
    length = 0;
    curr_min = 0;
}

template<typename T>
void Stack<T>::print_stack() {
    if (!is_empty()) {
        int len_copy = length;
        StackNode<T> *temp = top;
        while (len_copy > 0) {
            cout << temp->data << endl;
            temp = temp->next;
            len_copy--;
        }
    }
    else {
    cout << "The list is empty!" << endl;
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
    if (!is_empty()) {
        StackNode<T> *temp = top;
        T val = temp->data;
        top = top->next;
        delete temp;
        length--;
        return val;
    }
    cout << "The list is empty" << endl;
}

template<typename T>
void Stack<T>::push(T node) {
    if (is_empty()) {
        min_stack(node);
        top = new StackNode<T>(node);
    } else {
        min_stack(node);
        StackNode<T> *new_node = new StackNode<T>(node);
        StackNode<T> *temp = top;
        top = new_node;
        top->next = temp;
    }
    length++;
}

template<typename T>
void Stack<T>::min_stack(T node) {
    if(top_min == nullptr) {
        top_min = new StackNode<T>(node);
        curr_min = node;
    } else {
        if (curr_min >= node) {
            StackNode<T> *new_node = new StackNode<T>(node);
            StackNode<T> *temp = top_min;
            top_min = new_node;
            top_min->next = temp;
            curr_min = node;
        } else {
            StackNode<T> *new_node = new StackNode<T>(curr_min);
            StackNode<T> *temp = top_min;
            top_min = new_node;
            top_min->next = temp;
        }
    }
}


template<typename T>
T Stack<T>::pop_min() {
    if(top_min != nullptr) {
        T data = top_min->data;
        top_min = top_min->next;
        return data;
    } else {
        cout << "The stack is empty\n";
    }
}


template<typename T>
T Stack<T>::peek() {
    return top->data;
}

template<typename T>
Stack<T>::~Stack() {
}


int main() {
    Stack<int> stack;
    stack.push(23);
    stack.push(5);
    stack.push(10);
    stack.push(1);

    cout << stack.pop_min() << "\n";
    stack.pop();
    cout << stack.pop_min() << "\n";
    stack.pop();
    cout << stack.pop_min() << "\n";
    stack.pop();
    cout << stack.pop_min() << "\n";

}