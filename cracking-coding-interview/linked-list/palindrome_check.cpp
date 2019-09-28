// Copyright 2019 Kartik Madhira

// Check if a linked list is a palindrome.
#include "singly_linked_list.h"
#include <vector>

template<typename T>
bool palindrome_check(SinglyLinkedList<T> *list) {
    // store in a vector and then reverse it
    std::vector<T> rev_list;
    Node<T> *temp = list->tail;
    while(temp != nullptr) {
        rev_list.emplace_back(temp->value);
        temp = temp->next;
    }
    temp = list->tail;
    typename std::vector<T>::reverse_iterator it;
    for (it = rev_list.rbegin(); it != rev_list.rend(); ++it) {
        if(*it != temp->value) {
            return false;
        }
        temp = temp->next;
    }
    return true;
}

int main() {
    SinglyLinkedList<int> list;
    list.insert(2);
    list.insert(3);
    list.insert(5);
    list.insert(3);
    list.insert(5);
    list.insert(3);
    list.insert(2);
    list.insert(2);

    if(palindrome_check(&list)) {
        std::cout << "It is a palindrome" << std::endl;
    }
    else std::cout << "It is not a palindrome" << std::endl;
}