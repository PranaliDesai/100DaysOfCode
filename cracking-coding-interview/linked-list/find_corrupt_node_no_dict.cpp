// Copyright 2019 Kartik Madhira
// Output the corrupt node in a circular singly linked list
// without using a map 

#include "singly_linked_list.h"
template <typename T>
T find_corrupt_node(SinglyLinkedList<T> corr_list) {
    // Put a slow pointer and a faster pointer(k and 2k)
    Node<T> *slow_pointer, *fast_pointer;
    // Initialize both to the head of the pointer
    slow_pointer = corr_list.tail;
    fast_pointer = corr_list.tail;
    // Make them collide at (LOOP_SIZE-k), where k
    // is the number of nodes to the start of the corrupt
    // loop.
    while (fast_pointer != nullptr && fast_pointer->next != nullptr) {
        slow_pointer = slow_pointer->next;
        fast_pointer = fast_pointer->next->next;
        if (slow_pointer == fast_pointer) {
            break;
        }
    }
    // Now that they have collided, move the slow pointer to
    // the start of the linked list and move both pointers at
    // a pace of 1 node per unit time
    slow_pointer = corr_list.tail;
    while(slow_pointer != fast_pointer) {
        slow_pointer = slow_pointer->next;
        fast_pointer = fast_pointer->next;
    }
    return slow_pointer->value;
}

int main() {
    SinglyLinkedList<int> list;
    list.insert(2);
    list.insert(3);
    Node<int> a(nullptr, 49);
    list.add_node(a);
    list.insert(53);
    list.insert(33);
    list.insert(2);
    list.insert(3);
    list.insert(2);
    list.insert(3);
    list.add_node(a);
    cout << find_corrupt_node(list) << endl;
    // return 0;
}
