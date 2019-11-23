class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        // The idea is to have a 2D matrix of size Nx3
        // where the first index represents a subset sum from 0 to i
        // and the second index represents the remainder.
        
        int dp[nums.size()+1][3];
        
        // Initialize remained values
        dp[0][0] = 0;
        dp[0][1] = INT_MIN;
        dp[0][2] = INT_MIN;
        
        for (int i = 1; i<=nums.size(); i++) {
            int ind = i - 1;       
            dp[i][0] = max(dp[i-1][0], dp[i-1][(nums[ind])%3] + nums[ind]);
            
            dp[i][1] = max(dp[i-1][1], dp[i-1][(nums[ind]+1)%3] + nums[ind]);
            
            dp[i][2] = max(dp[i-1][2], dp[i-1][(nums[ind]+2)%3] + nums[ind]);
        }
        return dp[nums.size()][0];
    }
};


/* BRUTE FORCE APPROACH
 */
// // Copyright 2019, Kartik Madhira

// #include <iostream>
// #include <vector>

// using std::cout;
// using std::vector;


// void rec_sum(const vector<int> &main_arr, vector<int> &arr, int &top_sum, int index) {
//     int sum = 0;
//     for (auto &num : arr) {
//         sum += num;
//     }
//     if (sum%3 == 0 && sum > top_sum) {
//         top_sum = sum;
//     }
//     // Sanitize for the index
//     if (main_arr.empty()) {
//         return;
//     }
//     if (index > main_arr.size() - 1) {
//         return;
//     }
//     if (index <= main_arr.size() - 1) {
//         vector<int> left = arr;
//         left.emplace_back(main_arr[index]);

//         //     cout << "left: ";
//         // for (auto &num : left) {
//         //     cout << num << " ";
//         //     }

//         rec_sum(main_arr, left, top_sum, index+1);
//     }
//     if (index <= main_arr.size() - 1) {
//         vector<int> right = arr;
//         right.insert(right.end(), main_arr.begin()+index+1, main_arr.end());

//         // cout << "it came here\n";
//         // cout << "\nright: ";

//         // for (auto &num : right) {
//         //     cout << num << " ";
//         // }
//         vector<int> arr {};
//         rec_sum(right, arr, top_sum, 0);
//     }
// }


// int main() {
//     vector<int> main_arr{2, 3, 36, 8, 32, 38, 3, 30, 13, 40};
//     int top = 0;
//     vector<int> arr {};
//     rec_sum(main_arr, arr, top, 0);
//     cout << top << "\n";
// }