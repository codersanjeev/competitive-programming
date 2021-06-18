class Solution {
   public:
    int reductionOperations(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int ans = 0, cnt = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i - 1]) {
                ++cnt;
            }
            ans += cnt;
        }
        return ans;
    }
};