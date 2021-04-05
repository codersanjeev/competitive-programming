bool solve(int n) {
    long long lo = 0LL, hi = n;
    while (lo <= hi) {
        long long mid = lo + (hi - lo) / 2LL;
        long long x = mid * mid;
        if (x == n) {
            return true;
        }
        if (x < n) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return false;
}