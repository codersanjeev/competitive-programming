class Solution {
   private:
    int solve(const vector<int>& nums, int maxValue) {
        int ans = 0, curr = 0;
        for (const auto& ele : nums) {
            curr = ele <= maxValue ? curr + 1 : 0;
            ans += curr;
        }
        return ans;
    }

   public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        return solve(nums, right) - solve(nums, left - 1);
    }
};