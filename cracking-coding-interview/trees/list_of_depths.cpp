// Copyright 2019, Kartik Madhira
#include "linked_list.hpp"
#include "bin_tree.hpp"
#include <map>

using std::map;
template<typename T>
void list_of_depths(std::unique_ptr<Node<T>> &root, 
                    map<int, unique_ptr<SinglyLinkedList<T>>> &map, int depth) {
    if (map.find(depth) == map.end()) {
        auto temp = std::make_unique<SinglyLinkedList<T>>();
        temp->insert(root->value);
        map[depth] = std::move(temp);
    } else {
        auto temp = std::move(map.at(depth));
        temp->insert(root->value);
        map[depth] = std::move(temp);
    }
    if (root->left != nullptr) {
        list_of_depths(root->left, map, depth+1);
    }
    if (root->right != nullptr) {
        list_of_depths(root->right, map, depth+1);
    }
}

int main() {
    BT<int> *bin_tree = new BT<int>();
    bin_tree->insert(4);
    bin_tree->insert(6);
    bin_tree->insert(8);
    bin_tree->insert(9);
    bin_tree->insert(2);
    map<int, unique_ptr<SinglyLinkedList<int>>> map;
    list_of_depths(bin_tree->root_node, map, 0);
    for (auto &val : map) {
        cout << "At depth " << val.first << "\n";
        val.second->show_list();
        cout << "-------------\n";
    }
}