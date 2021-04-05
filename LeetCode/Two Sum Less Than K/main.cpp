class Solution {
   public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        int ans = -1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                int curr = nums[i] + nums[j];
                if (curr < k) {
                    ans = max(ans, curr);
                }
            }
        }
        return ans;
    }
};