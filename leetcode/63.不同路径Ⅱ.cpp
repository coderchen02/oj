// 2026.1.27 19点59分
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        //初始化
        int i,j;
        for(j=0;j<n;j++){
            if(obstacleGrid[0][j]==0)//没有障碍
                dp[0][j]=1;
            else{
                dp[0][j]=0;
                break;
            }
        }
        if(j<n) dp[0][j++]=0;
        for(i=0;i<m;i++){
            if(obstacleGrid[i][0]==0)
                dp[i][0]=1;
            else {
                dp[i][0]=0;
                break;
            }
        }
        if(i<m) dp[i++][0]=0;
        for(i=1;i<m;i++){
            for(j=1;j<n;j++){
                if(obstacleGrid[i][j]==0)
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[i-1][j-1];
    }
};