class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int dp_min[nums.size()+1][4];
        int dp_max[nums.size()+1][4];
        
        for (int i = 0; i <= nums.size(); i++) {
            for (int j = 0; j <= 3; j++) {
                if (i == 0 || j == 0) {
                    dp_max[i][j] = 1;
                    dp_min[i][j] = 1;
                    continue;
                }
                dp_max[i][j] = max(nums[i-1]*dp_max[i-1][j-1], nums[i-1]*dp_min[i-1][j-1]);
                dp_min[i][j] = min(nums[i-1]*dp_max[i-1][j-1], nums[i-1]*dp_min[i-1][j-1]);
                if (i > j) {
                     dp_max[i][j] = max(dp_max[i][j], dp_max[i-1][j]);
                     dp_min[i][j] = min(dp_min[i][j], dp_min[i-1][j]);

                }
            }
        }
        return dp_max[nums.size()][3];
    }
};