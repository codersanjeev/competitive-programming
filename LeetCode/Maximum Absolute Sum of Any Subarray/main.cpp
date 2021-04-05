class Solution {
   public:
    int maxAbsoluteSum(vector<int>& nums) {
        int mx = 0, mn = 0, curr = 0;
        for (const auto& ele : nums) {
            curr += ele;
            mx = max(mx, curr);
            mn = min(mn, curr);
        }
        return mx - mn;
    }
};