class Solution {
   public:
    int findPeakElement(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1, ans = nums.size() - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (mid + 1 < nums.size() and nums[mid] > nums[mid + 1]) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};