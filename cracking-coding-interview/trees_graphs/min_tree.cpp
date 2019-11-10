// Copyright 2019, Kartik Madhira
#include<vector>
#include "bin_search_tree.hpp"
using std::vector;


template<typename T>
int get_node(int start, int end, const vector<T> &array, BST<T> *bst) {
    int check = end - start;
    int mid = start + (check/2);
    if ((check >= 0) && (check < array.size())) {
        bst->insert(array.at(mid));
        get_node(start, mid - 1, array, bst);
        get_node(mid + 1, end, array, bst);
        return 0;
    }
}

template<typename T>
BST<T>* minimal_height(const vector<T> &array) {
    BST<T> *bst = new BST<T>();
    get_node<T>(0, array.size() - 1, array, bst);
    return bst;    
}


int main() {
    const vector<int> vec{1, 2, 3, 4, 5};
    BST<int> *bst = minimal_height(vec);
    bst->print_tree_inorder();
}