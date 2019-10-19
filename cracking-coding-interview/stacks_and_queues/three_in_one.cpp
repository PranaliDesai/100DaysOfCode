// Copyright 2019 Kartik Madhira

#include "queue.h"


int main() {
    Queue<int> new_node;
    new_node.queue(5);
    new_node.queue(4);
    // new_node.deque();

    new_node.queue(2);
    new_node.queue(1);
    // new_node.queue(5);

    cout << new_node.deque() << "\n";
    cout << new_node.deque() << "\n";
    cout << new_node.deque() << "\n";
    // cout << new_node.deque() << "\n";
    // cout << new_node.deque() << "\n";
    // cout << new_node.deque() << "\n";

    cout << new_node.peek() << "\n";
}