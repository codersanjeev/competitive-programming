class Solution {
   public:
    int maximumUniqueSubarray(vector<int> &nums) {
        int curr = 0, ans = 0, i = 0;
        vector<bool> seen(10001, false);
        for (int j = 0; j < nums.size(); ++j) {
            while (seen[nums[j]]) {
                seen[nums[i]] = false;
                curr -= nums[i];
                ++i;
            }
            seen[nums[j]] = true;
            curr += nums[j];
            ans = max(ans, curr);
        }
        return ans;
    }
};