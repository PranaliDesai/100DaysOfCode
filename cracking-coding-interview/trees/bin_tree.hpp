// Copyright 2019, Kartik Madhira
#pragma once

#include <vector>
#include <memory>
#include <iostream>
#include <map>
using std::unique_ptr;
using std::cout;

template<typename T>
class Node {
 public:
    T value;
    Node(T _value) : value(_value){}
    unique_ptr<Node<T>> left;
    unique_ptr<Node<T>> right;
};

template<typename T>
class BT {
public:
    BT();
    // Making it public so as to be able to make 
    // all questions accessible directly to root_node
    unique_ptr<Node<T>> root_node;
    bool inorder(T val);
    bool inorder_helper(unique_ptr<Node<T>> &root, T val);
    void insert(T val);
    int insert_helper(unique_ptr<Node<T>> &root, T val);
    void print_tree_preorder();
    void print_tree_helper(unique_ptr<Node<T>> &root);

};

template<typename T>
BT<T>::BT() {
    root_node = nullptr;
}

template<typename T>
bool BT<T>::inorder(T val) {
    return inorder_helper(root_node, val);
}

template<typename T>
bool BT<T>::inorder_helper(unique_ptr<Node<T>> &root, T val) {
        if (root->left != nullptr) {
            if (root->left->value == val) {
                cout << "Tree contains this value!\n";  

                return true;
            } else {
                inorder_helper(root->left, val);
            }
        if (root->value == val) {
                cout << "Tree contains this value!\n";  
                return true;
        }
        if (root->right != nullptr) {
            if (root->right->value == val) {
                cout << "Tree contains this value!\n";  
                return true;
            } else {
                inorder_helper(root->right, val);
            }
        }
    }
}

template<typename T>
void BT<T>::insert(T val) {
    insert_helper(root_node, val);
}

template<typename T>
int BT<T>::insert_helper(unique_ptr<Node<T>> &root, T val) {
    auto temp = std::make_unique<Node<T>>(val);
    if (root_node == nullptr) {
        root_node = std::move(temp);
        return 0;
    }
    if (root->left == nullptr) {
        root->left = std::move(temp);
        return 0;
    }
    if (root->right == nullptr) {
        root->right = std::move(temp);
        return 0;
    }
    if (root->left != nullptr) {
        insert_helper(root.get()->left, val);
    } else {
        insert_helper(root.get()->right, val);
    }
}


template<typename T>
void BT<T>::print_tree_preorder() {
    print_tree_helper(root_node);
}

template<typename T>
void BT<T>::print_tree_helper(unique_ptr<Node<T>> &root) {
   if (root != nullptr) {
       cout << root->value << "\n";
   }
   if (root->left != nullptr) {
       print_tree_helper(root->left);
   }
   if (root->right != nullptr) {
       print_tree_helper(root->right);
   }

}