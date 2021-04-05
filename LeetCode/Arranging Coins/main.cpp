class Solution {
   public:
    int arrangeCoins(int n) {
        int lo = 0, hi = n, ans = -1;
        while (lo <= hi) {
            long mid = lo + (hi - lo) / 2;
            long required = mid * (mid + 1) / 2;
            if (required <= n) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};