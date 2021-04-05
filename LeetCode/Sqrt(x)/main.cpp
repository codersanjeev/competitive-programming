class Solution {
   public:
    int mySqrt(int x) {
        int lo = 0, hi = x, ans = x;
        while (lo <= hi) {
            long mid = lo + (hi - lo) / 2;
            long curr = mid * mid;
            if (curr <= x) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};