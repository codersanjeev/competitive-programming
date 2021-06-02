class Solution {
   public:
    bool isInterleave(string x, string y, string z) {
        int a = x.size(), b = y.size(), c = z.size();
        if (a + b != c) return false;
        vector<vector<int>> dp(a + 1, vector<int>(b + 1));
        dp[0][0] = true;
        for (int i = 1; i <= a; ++i) {
            dp[i][0] = dp[i - 1][0] && (x[i - 1] == z[i - 1]);
        }
        for (int j = 1; j <= b; ++j) {
            dp[0][j] = dp[0][j - 1] && (y[j - 1] == z[j - 1]);
        }
        for (int i = 1; i <= a; ++i) {
            for (int j = 1; j <= b; ++j) {
                dp[i][j] = (dp[i - 1][j] && x[i - 1] == z[i + j - 1]) || (dp[i][j - 1] && y[j - 1] == z[i + j - 1]);
            }
        }
        return dp[a][b];
    }
};