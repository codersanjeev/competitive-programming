class Solution {
   public:
    int nthUglyNumber(int n, int a, int b, int c) {
        long A = (long)a;
        long B = (long)b;
        long C = (long)c;
        long AB = (A * B) / gcd(A, B);
        long BC = (B * C) / gcd(B, C);
        long CA = (C * A) / gcd(C, A);
        long ABC = (AB * C) / gcd(AB, C);
        long lo = 1, hi = 1e18, ans = 1;
        while (lo <= hi) {
            long mid = lo + (hi - lo) / 2;
            long cnt = mid / A + mid / B + mid / C - mid / AB - mid / BC - mid / CA + mid / ABC;
            if (cnt >= n) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};