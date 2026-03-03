// 3.3 21点07分
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // dp[i]表示以nums[i]结尾的最长递增子序列的长度
        if (nums.size() <= 1)
            return nums.size();
        vector<int> dp(nums.size(), 1);
        int result = 0;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            if (dp[i] > result)
                result = dp[i];
        }
        return result;
    }
};