// Copyright 2019 Kartik Madhira
// Return Kth element form last of a linked list

#include <iostream>
#include "singly_linked_list.h"


template<typename T>
T kth_element_from_last(SinglyLinkedList<T> *li_list, int k) {
    Node<T> *first_pointer, *second_pointer, *temp;
    temp = li_list->tail;
    while (k != 0) {
        li_list->tail = li_list->tail->next;
        k--;
    }
    second_pointer = li_list->tail;
    li_list->tail = temp;
    first_pointer = temp;
    while (second_pointer != nullptr) {
        first_pointer = first_pointer->next;
        second_pointer = second_pointer->next;
    }
    return first_pointer->value;
}



int main() {
    SinglyLinkedList<int> li_list;
    li_list.insert(1);
    li_list.insert(3);
    li_list.insert(100);
    li_list.insert(2);
    li_list.insert(3);
    li_list.insert(3);
    li_list.insert(100);
    li_list.insert(100);
    li_list.insert(100);
    li_list.insert(2);
    li_list.insert(100);
    li_list.insert(100);
    std::cout << kth_element_from_last(&li_list, 6) << "\n";

}