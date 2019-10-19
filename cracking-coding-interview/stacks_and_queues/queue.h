// Copyright 2019 Kartik Madhira

#pragma once
#include <iostream>

using std::cout;
using std::endl;

template <typename T>
class QueueNode {
public:
    QueueNode<T> *next;
    T data;
    QueueNode(T item) {
        this->data = item;
        this->next = nullptr;
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
    void print_queue();
private:
    // Keep two nodes first and last
    // Why? so that you can queue and deque in O(1)
    QueueNode<T> *first;
    QueueNode<T> *last;
};

template <typename T>
Queue<T>::Queue() {
    first = nullptr;
    last = nullptr;
}

// Here we update the last QueueNode member only
template <typename T>
void Queue<T>::queue(T item) {
    QueueNode<T> *new_node = new QueueNode<T>(item);
    if (last == nullptr) {
        last = new_node;
        first = last;
    }
    last->next = new_node;
    last = new_node;
}


template <typename T>
T Queue<T>::deque() {
    if (is_empty()) {
        cout << "The stack is empty\n";
        return 0;
    }
    if (first == nullptr) {
        return 0;
    }
    T data = first->data;
    QueueNode<T> *temp = first;
    first = first->next;
    if (first == nullptr) {
        last = nullptr;
    }
    delete(temp);
    return data;
}

template <typename T>
bool Queue<T>::is_empty() {
    if (first == nullptr && last == nullptr) {
        return true;
    } else {
        return false;
    }
}

template <typename T>
T Queue<T>::peek() {
    return last->data;
}


