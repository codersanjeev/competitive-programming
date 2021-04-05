class Solution {
   public:
    bool isMatch(string text, string pattern) {
        int n = pattern.size(), m = text.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1));
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = true;
                } else if (i == 0) {
                    dp[i][j] = false;
                } else if (j == 0) {
                    if (pattern[i - 1] == '*') {
                        dp[i][j] = dp[i - 2][j];
                    } else {
                        dp[i][j] = false;
                    }
                } else {
                    if (pattern[i - 1] == '*') {
                        dp[i][j] = dp[i - 2][j];
                        if (pattern[i - 2] == '.' || pattern[i - 2] == text[j - 1]) {
                            dp[i][j] = dp[i][j] || dp[i][j - 1];
                        }
                    } else if (pattern[i - 1] == '.' || pattern[i - 1] == text[j - 1]) {
                        dp[i][j] = dp[i - 1][j - 1];
                    } else {
                        dp[i][j] = false;
                    }
                }
            }
        }
        return dp[n][m];
    }
};