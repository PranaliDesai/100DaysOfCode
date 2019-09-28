// Copyright 2019 Kartik Madhira

// Remove the duplicates from an unsorted linked list.
// TO DO: This is a bad implementation of duplication as 
// pointers allocated with new in the linked list class
// are not being destroyed in the function.
#include <iostream>
#include "singly_linked_list.h" 
#include <map>
#include <iterator>

void remove_duplicates(SinglyLinkedList<int> *li_list) {
    // Create a hashmap of values present in the linked list 
    std::map<int, int> count_map;
    Node<int> *temp = li_list->tail;
    while (temp != nullptr) {
        count_map[temp->value]++;
        temp = temp->next;
    }
    li_list->tail = nullptr;
    // temp_list->show_list();
    std::map<int, int>::iterator it;
    for (it = count_map.begin();it != count_map.end();it++) {
        li_list->insert(it->first);
    }
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
    li_list.show_list();
    remove_duplicates(&li_list);
    li_list.show_list();
    return 0;
}

