class Solution {
   public:
    int numIdenticalPairs(vector<int> &nums) {
        int n = nums.size();
        vector<int> freq(101, 0);
        for (const auto &ele : nums) freq[ele]++;
        int ans = 0;
        for (const auto &ele : freq) ans += (ele * (ele - 1) / 2);
        return ans;
    }
};