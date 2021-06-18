class Solution {
   public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for (int mask = 1; mask < (1 << n); ++mask) {
            int curr = 0;
            for (int i = 0; i < n; ++i) {
                cout << (mask & (1 << i)) << "\n";
                if (mask & (1 << i)) curr ^= nums[i];
            }
            ans += curr;
        }
        return ans;
    }
};