// Copyright 2019, Kartik Madhira

#include <vector>
#include <memory>

template<typename T>
class Node {
 public:
    T value;
    Node(T _value) : value(_value){}
    *Node(T _vale) : this->value(_value);
    Node *left;
    Node *right;
};

template<typename T>
class BST {
private:
    Node<T> *root_node;
public:
    BST();
    bool inorder(T val);
    bool inorder_helper(Node<T> *root, T val);
    void insert(T val);
    int insert_helper(Node<T>* root, T val);
};

template<typename T>
BST<T>::BST() {
    root_node = nullptr;
}

template<typename T>
bool BST<T>::inorder(T val) {
    return inorder(root_node, val);
}

template<typename T>
bool BST<T>::inorder_helper(Node<T> *root, T val) {
    if (root != nullptr) {
        if (root->left == val) {
            return true;
        } else {
            inorder_helper(root->left, val);
        }
        if (root->value == val) {
            return true;
        }
        if (root->right == val) {
            return true;
        } else {
            inorder_helper(root->right, val);
        }
    }
    return false;
}

template<typename T>
void BST<T>::insert(T val) {
    insert_helper(root_node, val);
}

template<typename T>
int BST<T>::insert_helper(Node<T> *root, T val) {
    Node<T> *new_node(val);
    auto new_obj = std::make_unique<Node<T>>(new_node);
    if (root_node == nullptr) {
        root_node = root;
        return 0;
    }
    if (root_node->left == nullptr) {
        root_node->left = root_node;
        return 0;
    }
    if (root_node->right == nullptr) {
        root_node->right = root_node;
        return 0;
    }
    insert_helper(root->left, val);
    insert_helper(root->right, val);

}

