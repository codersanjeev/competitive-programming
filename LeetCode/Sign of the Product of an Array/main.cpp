class Solution {
   public:
    int arraySign(vector<int>& nums) {
        int ans = 0;
        for (const auto& ele : nums) {
            if (ele == 0) return 0;
            if (ele < 0) ++ans;
        }
        return (ans % 2 == 0 ? 1 : -1);
    }
};