// Time exceeding solution but full DFS solver.

class Node {
    public:
     int x;
     int y;
     Node(int _x, int _y) : x(_x), y(_y) {}
};

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 1 && n == 1) {
            return 1;
        }
        vector<vector<int>> b_map(n, vector<int>(m, 0));
        int count = 0;
        bool expand = false;
        stack<Node> s;
        int s_x = 0, s_y = 0;
        int prev_x = 0, prev_y = 0;
        int g_x = n-1, g_y = m-1;
        s.push(Node(s_x, s_y));
        while (!s.empty()) {
            int c_x = s.top().x;
            int c_y = s.top().y;
            int exp_count = 0;
            if (b_map[c_x][c_y] == 0) {
                if (b_check(c_x+1, c_y, m, n)) {
                    b_map[c_x+1][c_y] = 0;
                } 
                if (b_check(c_x, c_y+1, m, n)) {
                    b_map[c_x][c_y+1] = 0 ;
                }
            }
            if (b_check(c_x+1, c_y, m, n) && b_map[c_x][c_y] == 0) {
                s.push(Node(c_x+1, c_y));
                exp_count++;
            }
            if (b_check(c_x, c_y+1, m, n) && b_map[c_x][c_y] == 0) {
                s.push(Node(c_x, c_y+1));

                exp_count++;
            }
            if (exp_count != 0) {
                b_map[c_x][c_y] = 1;
            }
    
            if (exp_count == 0) {
                if (c_x == g_x && c_y == g_y) {
                    count++;
                    s.pop();
                }
                s.pop();
            }
            }
        return count;
    }
    bool b_check(int i, int j, int m, int n) {
        if (i > n - 1 || j > m - 1) {
            // cout << i << " " << j;
            return false;
        }
        return true;
    }
};