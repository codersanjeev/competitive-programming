int Solution::maxSubArray(const vector<int> &nums) {
    int n = nums.size();
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    for (int i = 1; i < n; i++) {
        dp[i] = nums[i] + (dp[i - 1] > 0 ? dp[i - 1] : 0);
    }
    return *max_element(dp.begin(), dp.end());
}
