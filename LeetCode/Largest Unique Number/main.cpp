class Solution {
   public:
    int largestUniqueNumber(vector<int>& A) {
        unordered_map<int, int> mp;
        for (const auto& ele : A) {
            mp[ele]++;
        }
        int ans = -1;
        for (const auto& ele : mp) {
            if (ele.second == 1) {
                ans = max(ans, ele.first);
            }
        }
        return ans;
    }
};