// Copyright 2019 Kartik Madhira

#include "stack.h"


int main() {
    Stack<int> new_node;
    new_node.push(5);
    new_node.push(7);
    new_node.push(88);
    new_node.push(3);
    new_node.push(12);
    new_node.print_stack();
    new_node.pop();
    new_node.print_stack();

}