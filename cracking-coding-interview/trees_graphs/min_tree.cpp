// Copyright 2019, Kartik Madhira

#include "bin_search_tree.hpp"


int main() {
    BT<int> bst;
    bst.insert(4);
    bst.insert(0);
    bst.insert(3);
    bst.insert(2);
    bst.insert(9);
    bst.inorder(9);
    // cout << bst.print_tree_preorder();
}