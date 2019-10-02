// Copyright 2019 Kartik Madhira
// Reverse a given linked list.

#include "singly_linked_list.h"

template <typename T>
SinglyLinkedList<T> reverse_list(SinglyLinkedList<T> &list) {
    Node<T> *prev, *curr, *next;
    prev = nullptr;
    curr = list.tail;
    while(curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    list.tail = prev;
    return list;
}


int main() {
    SinglyLinkedList<int> list;  
    list.insert(53);
    list.insert(33);
    list.insert(2);
    list.insert(3);
    list.insert(2);
    auto new_list = reverse_list(list);
    new_list.show_list();
    // return 0;
}