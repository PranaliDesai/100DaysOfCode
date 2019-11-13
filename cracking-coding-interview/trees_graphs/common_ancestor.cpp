// Copyright 2019, Kartik Madhira

#include "bin_tree_modified.hpp"

template<typename T>
void common_ancestor(int first, int second, 
                    shared_ptr<Node<T>> root) {
    int first_depth = 0;
    shared_ptr<Node<T>> first_node = nullptr; 
    search_node(first, first_depth, root, first_node);
    int second_depth = 0;
    shared_ptr<Node<T>> second_node = nullptr; 
    search_node(second, second_depth, root, second_node);
    int offset = abs(first_depth - second_depth);
    if (first_depth >= second_depth) {
        while (offset != 0) {
            first_node = std::move(first_node->parent);
            --offset;
        }
    } else {
        while (offset != 0) {
            second_node = std::move(second_node->parent);
            --offset;
        }
    }
    while(second_node->parent != first_node->parent) {
        if (second_node->parent == nullptr || 
            first_node->parent == nullptr ) {
                break;
            }
        first_node = first_node->parent;
        second_node = second_node->parent;
    }

    std::cout << "The common ancestor is: " << second_node->value << "\n";
}

template<typename T>
void search_node(int val, int &depth, 
                    shared_ptr<Node<T>> root,
                    shared_ptr<Node<T>> &node) {
    if (root->value == val) {
        node = root;
        return;
    }
    if (root->left != nullptr) {
        int left = depth+1;
        search_node(val, left, root->left, node);
    }
    if (root->right != nullptr) {
        int right = depth+1;
        search_node(val, right, root->right, node);
    }
}

int main() {

    BTModified<int> bin_tree ;
    bin_tree.insert(4);
    bin_tree.insert(6);
    bin_tree.insert(8);
    bin_tree.insert(9);
    bin_tree.insert(2);
    common_ancestor(2, 8, bin_tree.root_node);
    return 0;
}