// Copyright 2019, Kartik Madhira

#include "bin_tree_modified.hpp"
#include <random>

template<typename T>
void generate_random_node_helper(const shared_ptr<Node<T>> &node,
                          shared_ptr<Node<T>> &ret_node) {
    std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_int_distribution<> distr(0, node->nodes_below );
    int gen_index = distr(eng);
    if (gen_index == node->nodes_below ) {
        ret_node = node;
        return;
    }
    if (node->left != nullptr) {
        int left_size = node->left->nodes_below + 1;
        if (left_size > gen_index) {
            generate_random_node_helper(node->left, ret_node);
        } else {
            if (node->right != nullptr) {
                generate_random_node_helper(node->right, ret_node);
            }
        }
    }
}

template<typename T>
void generate_random_node(const BTModified<T> &bt, int &val) {
    shared_ptr<Node<T>> ret_node = nullptr;
    generate_random_node_helper(bt.root_node, ret_node);
    val = ret_node->value;
}


int main() {
    BTModified<int> tree_t1 ;
    tree_t1.insert(4);
    tree_t1.insert(6);
    tree_t1.insert(8);
    tree_t1.insert(9);
    tree_t1.insert(2);
    auto random_val = 0;
    generate_random_node(tree_t1, random_val);
    cout << random_val << "\n";
}

