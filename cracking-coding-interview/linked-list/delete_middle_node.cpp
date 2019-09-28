// Copyright 2019 Kartik Madhira
// Delete the middle node given access to only that node
// which is other than the start and the end node.

#include <iostream>
#include "singly_linked_list.h"

template<typename T>
void delete_middle_node (Node<T> *middle_node) {
    while (middle_node->next != nullptr) {
        middle_node->value = middle_node->next->value;
        middle_node = middle_node->next;
    }
    delete middle_node;
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
    std::cout << "Original list: " << "\n";
    li_list.show_list();
    Node<int> *temp = li_list.tail;
    int k = 0;
    while (k != 3) {
        li_list.tail = li_list.tail->next;
        k++;
    }
    std::cout << "middle node is: " << li_list.tail->value << "\n";
    delete_middle_node<int>(li_list.tail);
    li_list.tail = temp;
    std::cout << "Deleted list: " << "\n";
    li_list.show_list();
}


