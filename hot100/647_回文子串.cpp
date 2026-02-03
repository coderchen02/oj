// 2026.2.3 16点41分
class Solution {
public:
    int countSubstrings(string s) {
        // dp[i][j]表示区间范围[i,j]的字串是否是回文子串
        // 此题要注意遍历顺序 从下往上 从左往右
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int result = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i; j < s.size(); j++) {
                if (s[i] == s[j]) {
                    if (j - i <= 1) {
                        result++;
                        dp[i][j] = true;
                    } else if (dp[i + 1][j - 1]) {
                        result++;
                        dp[i][j] = true;
                    }
                }
            }
        }
        return result;
    }
};