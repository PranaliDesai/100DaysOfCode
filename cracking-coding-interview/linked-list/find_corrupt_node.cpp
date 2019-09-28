// Copyright 2019 Kartik Madhira
// Output the corrupt node in a circular singly linked list

#include "singly_linked_list.h"
#include <map>

using std::map;

template <typename T>
T corrupt_list_start(SinglyLinkedList<T> corrupt_list) {
    map<Node<T> *, int> address_map;
    Node<T> *curr_node = corrupt_list.tail ;
    while (address_map.find(curr_node) == address_map.end()) {
        address_map[curr_node] = 1;
        curr_node = curr_node->next;
    }
    return curr_node->value;
}

int main() {
    SinglyLinkedList<int> list;
    list.insert(2);
    list.insert(3);
    Node<int> a(nullptr, 3);
    list.add_node(a);
    list.insert(53);
    list.insert(33);
    list.insert(2);
    list.insert(3);
    list.insert(2);
    list.insert(3);
    list.add_node(a);
    cout << corrupt_list_start(list) << endl;
    // return 0;
}
