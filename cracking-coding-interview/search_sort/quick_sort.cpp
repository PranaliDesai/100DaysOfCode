// Copyright 2019, Kartik Madhira
#include <iostream>
#include <limits>
#include <vector>
#include <bits/stdc++.h> 

using std::vector;
using std::cout;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
} 

void partition(int i, int j, vector<int> &array) {
    if (i >= j || i >= array.size() || j < 0 || j >= array.size()) {
        return;
    }
    int min = INT_MAX;
    int start = i;
    int end = j;
    int pivot = array[i];
    j++;
    while (j >= i && i < array.size() && j >= 0) {
        // int ind = i+1;
        while (i <= array.size() && pivot > array[i+1]) {
            i++;
            // ind++;
        }
        if (i == array.size()) {
            swap(array[i-1], array[j++]);
            break;
        }
        if (pivot < array[i+1]) {
            i++;
        }
        while (min > pivot) {
            j--;
            min = array[j];
        }
        if (i > j) {
            break;
        } else {
            swap(array[i], array[j]);
        }
    }
    partition(start, j-1, array);
    cout << j+1 << end << "\n";
    partition(j+1, end, array);
}



int main() {
    vector<int> array = {1,9, 4};
    partition(0, array.size() - 1, array);
    for (auto &val : array) {
        cout << val << " ";
    }
    cout << "\n";



}