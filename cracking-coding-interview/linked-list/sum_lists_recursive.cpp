// Copyright 2019 Kartik Madhira
// Output the output of sum of two numbers all in linked list form
// This is the recursive variant to the previous sum problem

#include "singly_linked_list.h"

template<typename T>
Node<T> *add_node_list(Node<T> *first, Node<T> *second, bool carry) {
    int sum = 0;
    if (first == nullptr || second == nullptr) {
        return nullptr;
    }
    if (first != nullptr) {
        sum += first->value;
    }
    if (second != nullptr) {
        sum += second->value;
    }
    if(carry == true) {
        sum += 1;
    }
    int value = sum%10;
    bool carry_next;
    if (sum/10 > 0) {
        carry_next = true;
    }
    Node<T> *return_node = new Node<T>(nullptr, 0);
    return_node->value = value;
    if(first != nullptr || second != nullptr) {
        Node<T> *node = add_node_list(first->next, second->next, carry_next);
        return_node->next = node;
    }
    return return_node;
}


int main() {
    SinglyLinkedList<int> list1;
    list1.insert(7);
    list1.insert(1);
    list1.insert(6);
    
    SinglyLinkedList<int> list2;
    list2.insert(5);
    list2.insert(9);
    list2.insert(2);

    Node<int> *output_list = add_node_list(list1.tail, list2.tail, false);
    while (output_list != nullptr) {
        cout << output_list->value << "\n";
        output_list = output_list->next;
    }
    return 0;
}