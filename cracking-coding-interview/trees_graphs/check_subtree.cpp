// Copyright 2019, Kartik Madhira

#include "bin_tree_modified.hpp"

template<typename T>
bool check_subtree(BTModified<T> &T1, BTModified<T> &T2) {
    // Assuming T2 to be >>>> T1
    shared_ptr<Node<T>> node = nullptr;
    find_node(T1.root_node, T2.root_node->value, node);
    cout << node->value << "\n";
    if (node != nullptr) {
        if (match_tree(node, T2.root_node)) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

template<typename T>
bool match_tree(shared_ptr<Node<T>> node_t1,
                shared_ptr<Node<T>> node_t2) {  
    if (node_t1 == nullptr && node_t2 == nullptr) {
        return true;
    }
    if (node_t1 == nullptr ^ node_t2 == nullptr) {
        return false;
    }
    if (node_t1 != nullptr && node_t2 != nullptr) {
        if (node_t1->value != node_t2->value) {
            return false;
        }
        if (node_t1->value == node_t2->value) {
            bool first = match_tree(node_t1->left, node_t2->left);
            bool second = match_tree(node_t1->right, node_t2->right);
            return (first & second);
        }
    }
}

template<typename T>
void find_node(const shared_ptr<Node<T>> &root_t1, 
               const int value, shared_ptr<Node<T>> &found_node) {
    if (root_t1 != nullptr) {
        if (root_t1->value == value) {
            found_node = root_t1;
            return;
        }
        if (root_t1->left != nullptr) {
            find_node(root_t1->left, value, found_node);
        }
        if (root_t1->right, value, found_node) {
            find_node(root_t1->right, value, found_node);
        }
    }
}


int main() {
    BTModified<int> tree_t1 ;
    tree_t1.insert(4);
    tree_t1.insert(6);
    tree_t1.insert(8);
    tree_t1.insert(9);
    tree_t1.insert(2);

    BTModified<int> tree_t2 ;
    tree_t2.insert(6);
    tree_t2.insert(9);
    tree_t2.insert(2);

    cout << std::boolalpha << check_subtree(tree_t1, tree_t2);

}