int solve(int n) {
    long long lo = 0LL, hi = n, ans = 0LL;
    while (lo <= hi) {
        long long mid = lo + (hi - lo) / 2LL;
        if ((mid * mid) <= n) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return ans;
}