// Copyright 2019, Kartik Madhira

#include "stack.h"


template<typename T>
class MyQueue {
 public:
    MyQueue();
    void queue(T node);
    T dequeue();
    T peek();
    void reverse(Stack<T> *stack1, Stack<T> *stack2);
    bool is_empty(Stack<T> *stack);
    ~MyQueue();
 private:
    Stack<T> *oldest;
    Stack<T> *newest;
};


template<typename T>
MyQueue<T>::MyQueue() { 
    oldest = new Stack<T>();
    newest = new Stack<T>();
}

template<typename T>
void MyQueue<T>::queue(T node) {
    if(is_empty(newest)) {
        reverse(oldest, newest);
    }
    newest->push(node);
}

template<typename T>
T MyQueue<T>::dequeue() {
    if(is_empty(oldest)) {
        reverse(newest, oldest);
    }
    T data = oldest->pop();
    return data;
}

template<typename T>
void MyQueue<T>::reverse(Stack<T> *stack1, Stack<T> *stack2) {
    while (!stack1->is_empty()) {
        stack2->push(stack1->pop());
    }
}


template<typename T>
bool MyQueue<T>::is_empty(Stack<T> *stack) {
    if(stack->is_empty()) { 
        return true;
    }
    return false;
}

template<typename T>
MyQueue<T>::~MyQueue() { 
    delete oldest;
    delete newest;
}


int main() {
    MyQueue<int> queue;
    queue.queue(5);
    queue.queue(9);
    queue.queue(10);
    queue.queue(12);
    cout << queue.dequeue() << "\n";
    cout << queue.dequeue() << "\n";
    cout << queue.dequeue() << "\n";
    cout << queue.dequeue() << "\n";

}