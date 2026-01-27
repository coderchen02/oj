// 2026.1.27 18点31分
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        int i,j;
        //初始化
        for(j=1;j<=n;j++)
            dp[1][j]=1;
        for(i=1;i<=m;i++)
            dp[i][1]=1;
        for(i=2;i<=m;i++){
            for(j=2;j<=n;j++){
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[i-1][j-1];
    }
};