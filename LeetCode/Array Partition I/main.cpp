class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i += 2) {
            ans += nums[i];
        }
        return ans;
    }
};