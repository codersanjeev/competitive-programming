class Solution {
   public:
    int minPartitions(string s) {
        int ans = 0;
        for (const auto &ele : s) ans = max(ans, ele - '0');
        return ans;
    }
};