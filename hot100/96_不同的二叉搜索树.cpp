// 2026.1.27 20点51分
class Solution {
public:
    int numTrees(int n) {
        vector<int>dp(n+1,0) ;
        dp[0]=1;    //坑
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++)//枚举根节点
            {
                dp[i]+=dp[j-1]*dp[i-j];
            }
        }
        return dp[n];
    }
};