class Solution {
   public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = 0;
        for (const auto& ele : nums) {
            mp[ele]++;
            if (mp.find(ele + 1) != mp.end()) {
                ans = max(ans, mp[ele] + mp[ele + 1]);
            }
            if (mp.find(ele - 1) != mp.end()) {
                ans = max(ans, mp[ele] + mp[ele - 1]);
            }
        }
        return ans;
    }
};