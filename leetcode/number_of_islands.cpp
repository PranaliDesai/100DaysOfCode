// Copyright 2019, Kartik Madhira

#include <iostream>
#include <vector>
#include <stack>

using std::stack;
using std::vector;

class Node {
 public:
    int x;
    int y;
    bool visited;
    Node(int _x, int _y, bool _bool) : x(_x), y(_y), visited(_bool) {}
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int len = grid.size();
        if (len == 0) {
            return len;
        }
        
        int breadth = grid[0].size();
        vector<vector<int>> vec(len, vector<int> (breadth, 0));
        int count = 0;
        for (int i = 0; i < len ; i++) {
            for (int j = 0; j < breadth; j++) {
                if (vec[i][j] == 0 && grid[i][j] == '1') {
                    stack<Node> s;
                    s.push(Node(i,j, true));
                    while (!s.empty()) {
                        auto temp = s.top();
                        s.pop();
                        int i_temp = temp.x;
                        int j_temp = temp.y;
                        if (i_temp+1 < len) {
                            if (grid[i_temp+1][j_temp] == '1') {
                                if (vec[i_temp+1][j_temp] != 1 ) {
                                    s.push(Node(i_temp+1, j_temp, true));
                                    vec[i_temp+1][j_temp] = 1;
                                }
                            }
                        }
                        if ((j_temp + 1) < breadth) {
                            if (grid[i_temp][j_temp+1] == '1') {
                                if (vec[i_temp][j_temp+1] != 1) {
                                s.push(Node(i_temp, j_temp+1, true));
                                vec[i_temp][j_temp+1] = 1;
                                }
                            }
                        }
                        if ((i_temp - 1) >= 0) {
                            if (grid[i_temp-1][j_temp] == '1') {
                                if (vec[i_temp-1][j_temp] != 1) {
                                    s.push(Node(i_temp-1, j_temp, true));
                                    vec[i_temp-1][j_temp] = 1;
                                }
                            }
                        }
                        if ((j_temp - 1) >= 0 ) {
                            if (grid[i_temp][j_temp-1] == '1') {
                                if (vec[i_temp][j_temp-1] != 1) {
                                    s.push(Node(i_temp, j_temp-1, true));
                                    vec[i_temp][j_temp-1] = 1;
                                }
                            }
                        }
                    }
                    count++;

                    }
                }
            }
            return count;

        }
    };

