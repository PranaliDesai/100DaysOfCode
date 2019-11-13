// Copyright 2019, Kartik Madhira

#include <cmath>
#include <memory>
#include <iostream>

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