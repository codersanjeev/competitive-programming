class Solution {
   public:
    int singleNonDuplicate(const vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (mid % 2 == 1) {
                mid--;
            }
            if (nums[mid] != nums[mid + 1]) {
                hi = mid;
            } else {
                lo = mid + 2;
            }
        }
        return nums[lo];
    }
};