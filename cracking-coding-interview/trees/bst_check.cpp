//  Copyright 2019, Kartik Madhira

#include "bin_tree.hpp"
#include <cmath>
#include <limits>
using std::cout;

template<typename T>
bool check_bst(const unique_ptr<Node<T>> &root, 
                    T min, T max) {
    bool left_check = true;
    bool right_check = true;
    if (root->left != nullptr) {
        if (root->left->value > max) {
            left_check = false;
        }
    }
    if (root->right != nullptr) {
        if (root->right->value <= min) {
            right_check = false;
        }
    }
    if (root->left != nullptr) {
        left_check = (left_check & check_bst(root->left, 
                        root->left->value, max));
    }
    if (root->right != nullptr) {
        right_check = (right_check & check_bst(root->right, 
                        min, root->right->value));
    }
    return (left_check & right_check);
}

int main() {

    auto bin_s_tree = std::make_unique<BT<int>>();
    bin_s_tree->insert(9);
    bin_s_tree->insert(10);
    bin_s_tree->insert(17);
    bin_s_tree->insert(22);

    bin_s_tree->insert(3);
    bin_s_tree->insert(1);
    bin_s_tree->insert(2);

    cout << std::boolalpha<< check_bst(bin_s_tree->root_node,
                             bin_s_tree->root_node->value, 
                             bin_s_tree->root_node->value) << "\n";
    return 0;
}