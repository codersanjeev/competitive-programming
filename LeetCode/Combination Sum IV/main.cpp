#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> dp;

    int solve(const vector<int>& nums, int curr, int target) {
        if (dp[curr] != -1) return dp[curr];
        if (curr == target) {
            return dp[curr] = 1;
        }
        if (curr > target) {
            return dp[curr] = 0;
        }
        dp[curr] = 0;
        for (const auto& ele : nums) {
            dp[curr] += solve(nums, curr + ele, target);
        }
        return dp[curr];
    }

    int combinationSum4(vector<int>& nums, int target) {
        dp.resize(1e5, -1);
        return solve(nums, 0, target);
    }
};