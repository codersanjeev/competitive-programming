class Solution {
   private:
    vector<vector<int>> dp;

    int solve(const vector<int>& stones, int i, int j, int score) {
        if (i == j) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int a = score - stones[i] - solve(stones, i + 1, j, score - stones[i]);
        int b = score - stones[j] - solve(stones, i, j - 1, score - stones[j]);
        dp[i][j] = max(a, b);
        return dp[i][j];
    }

   public:
    int stoneGameVII(vector<int>& stones) {
        dp.resize(stones.size(), vector<int>(stones.size(), -1));
        return solve(
            stones,
            0,
            stones.size() - 1,
            accumulate(cbegin(stones), cend(stones), 0));
    }
};