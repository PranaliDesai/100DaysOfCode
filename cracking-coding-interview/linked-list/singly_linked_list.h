// Copyright 2019 Kartik Madhira
#pragma once
#include <iostream>

using std::cout;
using std::endl;

template <typename T>
struct Node {
    struct Node *next;
    T value;
    Node(Node *_next, T _val):next(_next), value(_val) {}
    Node();
};

template <typename T>
class SinglyLinkedList {
 protected:
    int length;
 public:
    SinglyLinkedList<T>():tail(nullptr), length(0) {}

    Node<T> *tail;
    void insert(T val);
    void remove(T val);
    void show_list();
    int find_pos(T val);
    void add_node(Node<T> &node);
    ~SinglyLinkedList();
};

template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList() {

    // Delete all the references to any pointers created
    // using new
    Node<T> *temp;
    while (tail->next == nullptr) {
        temp = tail->next;
        delete tail->next;
        tail = tail->next;
    }
    delete tail;
}

template <typename T>
int SinglyLinkedList<T>::find_pos(T val) {
    int position = 0;
    Node<T> *temp = tail;
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
    Node<T> *temp, *temp_tail;
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
        tail = new Node<T>(nullptr, val);
    } else {
        Node<T> *temp = tail;
        while (tail->next != nullptr) {
            tail = tail->next;
        }
        tail->next = new Node<T>(nullptr, val);
        tail = temp;
    }
    length++;
}

template <typename T>
void SinglyLinkedList<T>::show_list() {
    Node<T> *temp = tail;
    while (temp != nullptr) {
        std::cout << temp->value << "\n";
        temp = temp->next;
    }
    tail = temp;
}

template <typename T>
void SinglyLinkedList<T>::add_node(Node<T> &node) {
    if (tail == nullptr) {
        tail = &node;
    } else {
        Node<T> *temp = tail;
        while (tail->next != nullptr) {
            tail = tail->next;
        }
        tail->next = &node;
        tail = temp;
    }
    length++;
}
