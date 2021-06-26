class Solution {
   public:
    long long maxAlternatingSum(vector<int> &nums) {
        long long ans = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            ans += max(0LL, (long long)(nums[i] - nums[i - 1]));
        }
        return ans;
    }
};