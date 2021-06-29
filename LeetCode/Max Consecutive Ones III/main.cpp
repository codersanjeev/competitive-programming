class Solution {
   public:
    int longestOnes(vector<int>& nums, int k) {
        int lo = 0, hi = 0;
        while (hi < nums.size()) {
            if (nums[hi] == 0) --k;
            if (k < 0) {
                if (nums[lo] == 0) ++k;
                ++lo;
            }
            ++hi;
        }
        return hi - lo;
    }
};