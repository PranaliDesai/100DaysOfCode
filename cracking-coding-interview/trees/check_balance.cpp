//  Copyright 2019, Kartik Madhira

#include "bin_search_tree.hpp"
#include <cmath>

using std::cout;
template<typename T>
bool check_balanced(const unique_ptr<Node<T>> &root, 
                    int left_depth, int right_depth) {
    bool left_check = true;
    bool right_check = true;
    if (root->left != nullptr) {
        left_check = check_balanced(root->left, left_depth+1, right_depth);
    }
    if (root->right != nullptr) {
        right_check = check_balanced(root->right, left_depth, right_depth+1);
    }
    left_check = (left_check & right_check);
    if (abs(right_depth - left_depth) > 1) {
        left_check = false;
    }
    return left_check;
}

int main() {

    auto bin_s_tree = std::make_unique<BST<int>>();
    bin_s_tree->insert(9);
    bin_s_tree->insert(10);
    bin_s_tree->insert(3);
    bin_s_tree->insert(1);
    bin_s_tree->insert(2);

    cout << std::boolalpha<< check_balanced(bin_s_tree->root_node, 0, 0) << "\n";
    return 0;
}