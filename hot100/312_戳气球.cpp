//3.11 21点27分
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 2,vector<int>(n + 2,0));
        //创建一个辅助数组，并在首尾各添加1，方便处理边界情况
        vector<int> temp(n + 2);
        temp[0] = 1;
        temp[n + 1] = 1;
        for(int i = 1; i <= n; i++)
            temp[i] = nums[i - 1];
         // 遍历所有可能的开区间长度（len=3 对应区间(l, r)内有1个气球，len最大为n+2 对应整个区间(0, n+1)）
        for(int len = 3; len <= n + 2; len++) {
            //l表示开区间左端点,l + len - 1则表示开区间右端点
            for(int l = 0; l <= n + 2 - len; l++) {
                //k为开区间内的索引（代表区间最后一个被戳破的气球）
                for(int k = l + 1; k < l + len - 1; k++) {
                    int left = dp[l][k];
                    int right = dp[k][l + len - 1];
                    int sum = left + right + temp[k] * temp[l] * temp[l + len - 1];
                    dp[l][l + len - 1] = max(dp[l][l + len - 1],sum);//取金币最大值
                }
            }
        }
        return dp[0][n + 1];// 最终结果：戳破整个区间(0, n+1)内的所有气球（即原数组所有气球）
    }
};