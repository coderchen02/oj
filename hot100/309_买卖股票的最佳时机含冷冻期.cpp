//3.11 21点46分
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*
        dp[i][0]表示第i天持股状态
        dp[i][1]表示第i天保持买完股状态
        dp[i][2]表示第i天卖出股状态
        dp[i][3]表示第i天是冷冻期状态
        */
        int n = prices.size();
        if (n == 0) return 0;
        vector<vector<int>> dp(n, vector<int>(4, 0));
        dp[0][0] -= prices[0]; // 持股票
        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][3], dp[i - 1][1]) - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][3]); //i保持卖完股--->前一天也是卖完股和冷冻期最大值
            dp[i][2] = dp[i - 1][0] + prices[i];        //i卖出股票--->前一天持股
            dp[i][3] = dp[i - 1][2];         // i是冷冻期--->前一天卖出股票
        }
        return max(dp[n - 1][3],max(dp[n - 1][1], dp[n - 1][2]));
    }
};
