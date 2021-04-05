class Solution {
   public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ans;
        int left = lower, right = upper, n = nums.size();
        for (int i = 0; i <= n; i++) {
            if (i > 0) {
                left = nums[i - 1] + 1;
            }
            right = (i == n ? upper : nums[i] - 1);
            if (right == left - 1) {
                continue;
            }
            if (left == right) {
                ans.push_back(to_string(left));
            } else {
                ans.push_back(to_string(left) + "->" + to_string(right));
            }
        }
        return ans;
    }
};