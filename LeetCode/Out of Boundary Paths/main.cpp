class Solution {
   private:
    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};
    int mod = 1e9 + 7;
    int dp[51][51][51];

   public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        if (startRow < 0 || startColumn < 0 || startRow >= m || startColumn >= n) {
            return 1;
        }
        if (maxMove == 0) return 0;
        if (dp[maxMove][startRow][startColumn] != 0) {
            return dp[maxMove][startRow][startColumn];
        }
        int ans = 0;
        for (int k = 0; k < 4; ++k) {
            ans = (ans + findPaths(m, n, maxMove - 1, startRow + dx[k], startColumn + dy[k])) % mod;
        }
        dp[maxMove][startRow][startColumn] = ans;
        return ans;
    }
};