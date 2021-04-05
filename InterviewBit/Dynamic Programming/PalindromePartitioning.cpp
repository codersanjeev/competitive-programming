bool isPalindrome(const string &s, int i, int j, vector<vector<int>> &cache) {
    if (cache[i][j] != -1) {
        return cache[i][j];
    }
    while (i < j) {
        if (s[i] != s[j]) {
            return cache[i][j] = false;
        }
        i++;
        j--;
    }
    return cache[i][j] = true;
}

int solve(const string &s, int i, int j, vector<vector<int>> &cache, vector<vector<int>> &dp) {
    if (i >= j || isPalindrome(s, i, j, cache)) {
        return 0;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    int ans = INT_MAX;
    for (int k = i; k < j; k++) {
        int x = -1, y = -1;
        if (dp[i][k] != -1) {
            x = dp[i][k];
        } else {
            x = solve(s, i, k, cache, dp);
            dp[i][k] = x;
        }
        if (dp[k + 1][j] != -1) {
            y = dp[k + 1][j];
        } else {
            y = solve(s, k + 1, j, cache, dp);
            dp[k + 1][j] = y;
        }
        ans = min(ans, x + y + 1);
    }
    return dp[i][j] = ans;
}

int Solution::minCut(string s) {
    int n = s.size();
    vector<vector<int>> cache(n, vector<int>(n, -1));
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return solve(s, 0, n - 1, cache, dp);
}
