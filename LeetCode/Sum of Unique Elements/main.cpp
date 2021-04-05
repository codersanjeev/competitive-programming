class Solution {
   public:
    int sumOfUnique(vector<int> &nums) {
        unordered_map<int, int> mp;
        for (const auto &ele : nums) {
            mp[ele]++;
        }
        int ans = 0;
        for (const auto &ele : mp) {
            if (ele.second == 1) {
                ans += ele.first;
            }
        }
        return ans;
    }
};