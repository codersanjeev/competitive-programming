int dp[151][151][2];
int helper(string s, int i, int j, bool isTrue) {
    if (i > j) {
        return dp[i][j][isTrue] = 0;
    }
    if (i == j) {
        if (isTrue) {
            return dp[i][j][isTrue] = (s[i] == 'T' ? 1 : 0);
        } else {
            return dp[i][j][isTrue] = (s[i] == 'F' ? 1 : 0);
        }
    }
    if (dp[i][j][isTrue] != -1) {
        return dp[i][j][isTrue];
    }
    int ans = 0;
    for (int k = i + 1; k < j; k += 2) {
        if (dp[i][k - 1][1] == -1) {
            dp[i][k - 1][1] = helper(s, i, k - 1, true);
        }
        if (dp[i][k - 1][0] == -1) {
            dp[i][k - 1][0] = helper(s, i, k - 1, false);
        }
        if (dp[k + 1][j][1] == -1) {
            dp[k + 1][j][1] = helper(s, k + 1, j, true);
        }
        if (dp[k + 1][j][0] == -1) {
            dp[k + 1][j][0] = helper(s, k + 1, j, false);
        }
        int lt = dp[i][k - 1][1];
        int lf = dp[i][k - 1][0];
        int rt = dp[k + 1][j][1];
        int rf = dp[k + 1][j][0];
        if (s[k] == '&') {
            ans = (ans + (isTrue ? (rt * lt) : (lt * rf + lf * rt + lf * rf))) % 1003;
        }
        if (s[k] == '|') {
            ans = (ans + (isTrue ? (lt * rf + lf * rt + lt * rt) : lf * rf)) % 1003;
        }
        if (s[k] == '^') {
            ans = (ans + (isTrue ? (lt * rf + lf * rt) : (lt * rt + lf * rf))) % 1003;
        }
    }
    return ans % 1003;
}
int Solution::cnttrue(string A) {
    memset(dp, -1, sizeof(dp));
    return helper(A, 0, A.length() - 1, true);
}