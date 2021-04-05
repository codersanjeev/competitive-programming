class Solution {
   public:
    int maximumScore(vector<int> &nums, vector<int> &multipliers) {
        int n = nums.size();
        int m = multipliers.size();
        vector<int> dp(m + 1, 0);
        for (int t = 0; t < m; t++) {
            vector<int> tempDP(m + 1, INT_MIN);
            for (int i = 0; i <= t; i++) {
                int j = n - 1 - (t - i);
                tempDP[i + 1] = max(tempDP[i + 1], multipliers[t] * nums[i] + dp[i]);
                tempDP[i] = max(tempDP[i], multipliers[t] * nums[j] + dp[i]);
            }
            dp = tempDP;
        }
        return *max_element(dp.begin(), dp.end());
    }
};