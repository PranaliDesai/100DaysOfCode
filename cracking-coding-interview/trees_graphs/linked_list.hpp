// Copyright 2019 Kartik Madhira
#pragma once
#include <iostream>

using std::cout;
using std::endl;

template <typename T>
struct Node_LL {
    struct Node_LL *next;
    T value;
    Node_LL(Node_LL *_next, T _val):next(_next), value(_val) {}
};

template <typename T>
class SinglyLinkedList {
 protected:
    int length;
 public:
    SinglyLinkedList<T>():tail(nullptr), length(0) {}

    Node_LL<T> *tail;
    void insert(T val);
    void remove(T val);
    void show_list();
    int find_pos(T val);
    void add_node(Node_LL<T> &node);
    ~SinglyLinkedList();
};

template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList() {

    // Delete all the references to any pointers created
    // using new
    Node_LL<T> *temp;
    while (tail != nullptr) {
        temp = tail->next;
        delete tail->next;
        tail = tail->next;
    }
    delete tail;
}

template <typename T>
int SinglyLinkedList<T>::find_pos(T val) {
    int position = 0;
    Node_LL<T> *temp = tail;
    while (tail->value != val) {
        tail = tail->next;
        position++;
    }
    tail = temp;
    return position;
}

// Removes the first reference
template <typename T>
void SinglyLinkedList<T>::remove(T val) {
    Node_LL<T> *temp, *temp_tail;
    if (SinglyLinkedList::find_pos(val) == 0) {
        temp = tail;
        tail = temp->next;
    } else {
        temp_tail = tail;
        while (tail->next->value != val) {
            tail = tail->next;
        }
        temp = tail->next;
        tail->next = tail->next->next;
        delete temp;
        tail = temp_tail;
        }
    length--;
}

template <typename T>
void SinglyLinkedList<T>::insert(T val) {
    if (tail == nullptr) {
        tail = new Node_LL<T>(nullptr, val);
    } else {
        Node_LL<T> *temp = tail;
        while (tail->next != nullptr) {
            tail = tail->next;
        }
        tail->next = new Node_LL<T>(nullptr, val);
        tail = temp;
    }
    length++;
}

template <typename T>
void SinglyLinkedList<T>::show_list() {
    Node_LL<T> *temp = tail;
    while (temp != nullptr) {
        std::cout << temp->value << "\n";
        temp = temp->next;
    }
    tail = temp;
}

template <typename T>
void SinglyLinkedList<T>::add_node(Node_LL<T> &node) {
    if (tail == nullptr) {
        tail = &node;
    } else {
        Node_LL<T> *temp = tail;
        while (tail->next != nullptr) {
            tail = tail->next;
        }
        tail->next = &node;
        tail = temp;
    }
    length++;
}
