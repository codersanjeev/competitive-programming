#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int longestIncreasingPath(vector<vector<int>> &matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ans = max(ans, dfs(matrix, dp, i, j, n, m));
            }
        }
        return ans;
    }

   private:
    vector<int> dx = {0, 0, -1, 1};
    vector<int> dy = {1, -1, 0, 0};

    int dfs(vector<vector<int>> &matrix, vector<vector<int>> &dp, int i, int j, int n, int m) {
        if (dp[i][j] > 0) return dp[i][j];
        int ans = 1;
        for (int k = 0; k < 4; ++k) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            if (ni < 0 || nj < 0 || ni >= n || nj >= m || matrix[ni][nj] <= matrix[i][j]) {
                continue;
            }
            ans = max(ans, 1 + dfs(matrix, dp, ni, nj, n, m));
        }
        return dp[i][j] = ans;
    }
};