// Copyright 2019, Kartik Madhira

#include <cmath>
#include <memory>
#include <iostream>

using std::unique_ptr;
using std::shared_ptr;
using std::cout;

template<typename T>
class Node {
 public:
    T value;
    Node(T _value) : value(_value){}
    shared_ptr<Node<T>> left;
    shared_ptr<Node<T>> right;
    shared_ptr<Node<T>> parent;

};

template<typename T>
class BTModified {
public:
    BTModified();
    // Making it public so as to be able to make 
    // all questions accessible directly to root_node
    shared_ptr<Node<T>> root_node;
    void insert(T val);
    int insert_helper(shared_ptr<Node<T>> &root, T val);
    ~BTModified();
};

template<typename T>
BTModified<T>::BTModified() {
    root_node = nullptr;
}

template<typename T>
BTModified<T>::~BTModified() {

}
template<typename T>
void BTModified<T>::insert(T val) {
    insert_helper(root_node, val);
}

template<typename T>
int BTModified<T>::insert_helper(shared_ptr<Node<T>> &root, T val) {
    auto temp = std::make_shared<Node<T>>(val);
    if (root_node == nullptr) {
        temp->parent = nullptr;
        root_node = temp;
        return 0;
    }
    if (root->left == nullptr) {
        temp->parent = root;
        root->left = temp;
        return 0;
    }
    if (root->right == nullptr) {
        temp->parent = root;
        root->right = temp;
        return 0;
    }
    if (root->left != nullptr) {
        insert_helper(root.get()->left, val);
    } else {
        insert_helper(root.get()->right, val);
    }
}


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