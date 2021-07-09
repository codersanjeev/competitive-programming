class Solution {
   public:
    int findLength(vector<int>& A, vector<int>& B) {
        int n = A.size(), m = B.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                if (A[i] == B[j]) {
                    dp[i][j] = dp[i + 1][j + 1] + 1;
                }
            }
        }
        int ans = 0;
        for (const auto& row : dp) {
            for (const auto& ele : row) {
                ans = max(ans, ele);
            }
        }
        return ans;
    }
};