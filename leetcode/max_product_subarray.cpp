class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        int dp_max[nums.size()];    
        int dp_min[nums.size()];    
        dp_max[0] = nums[0];
        dp_min[0] = nums[0];
        int max_product = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            dp_max[i] = max(max(nums[i]*dp_max[i-1], nums[i]*dp_min[i-1]), nums[i]);
            dp_min[i] = min(min(nums[i]*dp_max[i-1], nums[i]*dp_min[i-1]), nums[i]);
            max_product = max(max_product, dp_max[i]);
        }
        return max_product;
    }
};