// Copyright 2019 Kartik Madhira

#pragma once
#include <iostream>

using std::cout;
using std::endl;

template <typename T>
class QueueNode {
public:
    QueueNode<T> next;
    T data;
    QueueNode(T item) {
        this->data = item;
    }
};

template <typename T>
class Queue {
public:
    // add, remove, peek and is_empty check
    Queue();
    void queue(T item);
    T deque();
    T peek();
    bool is_empty();
private:
    // Keep two nodes first and last
    // Why? so that you can queue and deque in O(1)
    QueueNode<T> *first;
    QueueNode<T> *last;
    int length;
};

template <typename T>
Queue<T>::Queue() {
    first == nullptr;
    last == nullptr;
    length = 0;
}

// Here we update the last QueueNode member only
template <typename T>
void Queue<T>::queue(T item) {
    QueueNode<T> new_node = new QueueNode<T>(item);
    if (last == nullptr) {
        last = new_node;
    } else {
        QueueNode<T> *temp = last;
        last = new_node;
        last->next = temp;
    }
    if (first == nullptr) {
        first = last;
    }
    
}

template <typename T>
T Queue<T>::deque() {
    
}





