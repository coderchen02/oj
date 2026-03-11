//3.11 20点39分
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        // dp[i][j] 代表 s 的前 i 个和 p 的前 j 个能否匹配
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        // 基础情况：空字符串与空模式匹配
        dp[0][0] = true;

        // 初始化：处理 s 为空，p 不为空的情况（如 a*b*c* 可以匹配空串）
        for (int j = 2; j <= n; j++) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] == '*') {
                    // 情况1：* 匹配 0 次，直接看 p[j-2] 之前是否匹配
                    dp[i][j] = dp[i][j - 2];
                    
                    // 情况2：* 匹配 1 次或多次
                    // 必须满足 s[i-1] 能匹配 p[j-2]
                    if (s[i - 1] == p[j - 2] || p[j - 2] == '.') {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                } else {
                    // 普通字符匹配或 '.' 匹配
                    if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                }
            }
        }

        return dp[m][n];
    }
};