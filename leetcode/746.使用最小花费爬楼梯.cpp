/// 2026.1.27 15点15分
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1);
        dp[0]=0;
        dp[1]=0;
        int n=cost.size(),i;
        for(i=2;i<=n;i++)
            dp[i]=min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2]);
        return dp[i-1];
    
    }
};