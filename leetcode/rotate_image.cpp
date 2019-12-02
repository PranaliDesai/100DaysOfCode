class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // first transpose
        // Next, swap the columns
        int n = matrix.size();
        for (int i = 0; i < n ; i++) {
            for (int j = i+1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // now swap columns from first to last, second to second last
        for (int i = 0; i < n ; i++) {
            for (int j = 0; j < n/2; j++) {
                swap(matrix[i][j], matrix[i][n-j-1]);
            }
        }
        
    }
    void swap (int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }
};