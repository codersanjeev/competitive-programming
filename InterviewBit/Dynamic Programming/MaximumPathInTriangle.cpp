int Solution::solve(vector<vector<int>> &A) {
    int N = A.size();
    vector<vector<int>> dp(N, vector<int>(N, 0));
    for (int j = 0; j < N; j++) {
        dp[N - 1][j] = A[N - 1][j];
    }
    for (int i = N - 2; i >= 0; i--) {
        for (int j = 0; j < N - 1; j++) {
            dp[i][j] = A[i][j] + max(dp[i + 1][j], dp[i + 1][j + 1]);
        }
    }
    return dp[0][0];
}