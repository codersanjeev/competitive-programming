int Solution::solve(vector<vector<int>> &A) {
    int N = A.size();
    vector<int> dp(N, 1);
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            int a = A[j][0];
            int b = A[j][1];
            int c = A[i][0];
            int d = A[i][1];
            if (b < c) {
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}