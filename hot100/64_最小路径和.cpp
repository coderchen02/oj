// 2026.2.2 21点29分
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        //初始化
        int i=0,j=0;
        dp[0][0]=grid[0][0];
        for(j=1;j<n;j++)
            dp[0][j]=dp[0][j-1]+grid[0][j];
        for(i=1;i<m;i++)
            dp[i][0]=dp[i-1][0]+grid[i][0];
        for(i=1;i<m;i++)
            for(j=1;j<n;j++)
                dp[i][j]=min(dp[i-1][j]+grid[i][j],dp[i][j-1]+grid[i][j]);
        return dp[i-1][j-1];
    }
};