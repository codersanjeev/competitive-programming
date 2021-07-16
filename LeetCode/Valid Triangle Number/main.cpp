class Solution {
   public:
    int triangleNumber(vector<int>& nums) {
        sort(begin(nums), end(nums));
        auto binarySearch = [&](int i, int target) -> int {
            int lo = i, hi = nums.size() - 1, ans = 0;
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                if (nums[mid] < target) {
                    ans = mid + 1 - i;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            return ans;
        };
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                ans += binarySearch(j + 1, nums[i] + nums[j]);
            }
        }
        return ans;
    }
};