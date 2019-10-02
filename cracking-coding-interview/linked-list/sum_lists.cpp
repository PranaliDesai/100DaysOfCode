// Copyright 2019 Kartik Madhira
// Output the output of sum of two numbers all in linked list form0

#include "singly_linked_list.h"
#include <cmath>
template <typename T>
SinglyLinkedList<T> sum_first(SinglyLinkedList<T> &first, 
                              SinglyLinkedList<T> &second) {
        
    // Get the number of digits in one pass
    int n1 = 0; 
    int n2 = 0;
    Node<T> *temp = first.tail;
    while (temp != nullptr) {
        n1++;
        temp = temp->next;
    }
    temp = second.tail;
    while (temp != nullptr) {
        n2++;
        temp = temp->next;
    }
    // Sum up both numbers
    temp = first.tail;
    int num1 = 0 ;
    for (int i = 1; i <= n1; ++i) {
        num1 += std::pow(10, i-1)*temp->value;
        temp = temp->next;
    }
    temp = second.tail;
    int num2 = 0;
    for (int i = 1; i <= n2; ++i) {
        num2 += std::pow(10, i-1)*temp->value;
        temp = temp->next;
    }

    num1 += num2;
    SinglyLinkedList<T> output_list;
    while (num1 > 0) {
        int digit = num1 % 10;
        output_list.insert(digit);
        num1 /= 10;
    }
    return output_list;
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

    SinglyLinkedList<int> output_list = sum_first(list1, list2);
    output_list.show_list();
    return 0;
}
