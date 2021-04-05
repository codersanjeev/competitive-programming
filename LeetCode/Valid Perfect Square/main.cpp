class Solution {
   public:
    bool isPerfectSquare(int num) {
        int lo = 0, hi = num;
        while (lo <= hi) {
            long mid = lo + (hi - lo) / 2;
            long curr = mid * mid;
            if (curr == num) {
                return true;
            } else if (curr < num) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return false;
    }
};