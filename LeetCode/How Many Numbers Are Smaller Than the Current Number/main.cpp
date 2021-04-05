class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        if (nums.empty()) return nums;
        int n = nums.size();
        vector<int> ans(n, 0), freq(101, 0);
        for (const auto &ele : nums) freq[ele]++;
        for (int i = 1; i < 101; i++) freq[i] += freq[i - 1];
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) ans[i] = 0;
            else ans[i] = freq[nums[i] - 1];
        }
        return ans;
    }
};