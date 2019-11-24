class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
         if (nums.size() == 0) {
            return 0;
        }
        int max_till_i = 0;
        int maxS = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            max_till_i = max(nums[i] + max_till_i, nums[i]);
            maxS = max(maxS, max_till_i);
        }
        return maxS;
    }
};