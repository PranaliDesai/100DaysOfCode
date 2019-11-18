// Copyright 2019, Kartik Madhira

#include <vector>
#include <memory>
#include <iostream>

using std::unique_ptr;
using std::cout;

template<typename T>
class Node {
 public:
    T value;
    Node(T _value) : value(_value){}
    unique_ptr<Node<T>> left;
    unique_ptr<Node<T>> right;
    int _depth;
};

template<typename T>
class BST {
public:
    BST();
    unique_ptr<Node<T>> root_node;
    // bool inorder(T val);
    // bool inorder_helper(unique_ptr<Node<T>> &root, T val);
    void insert(T val);
    int insert_helper(unique_ptr<Node<T>> &root, T val, int depth);
    void print_tree_inorder();
    void print_tree_helper(unique_ptr<Node<T>> &root);
    int depth;
};

template<typename T>
BST<T>::BST() {
    root_node = nullptr;
    depth = 0;
}

template<typename T>
void BST<T>::insert(T val) {
    insert_helper(root_node, val, 0);
}

template<typename T>
int BST<T>::insert_helper(unique_ptr<Node<T>> &root, T val, int depth) {
    std::unique_ptr<Node<T>> temp = std::make_unique<Node<T>>(val);
    if (root == nullptr) {
        temp->_depth = depth++;
        root = std::move(temp);
        return 0;
    }
    if (val <= root->value) {
        if (root->left != nullptr) {
            temp->_depth = depth++;
            insert_helper(root->left, val, depth);
        } else {
            temp->_depth = depth;
            root->left = std::move(temp);
        }
    } else {
        if (root->right != nullptr) {
            temp->_depth = depth++;
            insert_helper(root->right, val, depth);
        } else {
            temp->_depth = depth;
            root->right = std::move(temp);
        }
    }
}

template<typename T>
void BST<T>::print_tree_inorder() {
    print_tree_helper(root_node);
}

template<typename T>
void BST<T>::print_tree_helper(unique_ptr<Node<T>> &root) { 
 if (root != nullptr) {
       cout << root->value << " at depth " << root->_depth<< " \n";
   }
   if (root->left != nullptr) {
       print_tree_helper(root->left);
   }
   if (root->right != nullptr) {
       print_tree_helper(root->right);
   }
}
