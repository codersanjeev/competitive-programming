const int mod = 1e9 + 7;

long long largestPowerOfTwo(long long n) {
    long long x = 0LL;
    while ((1LL << x) <= n) {
        x++;
    }
    return x - 1;
}

int Solution::solve(int n) {
    if (n == 0) {
        return 0;
    }
    long long x = largestPowerOfTwo(n);
    long long ans = x * (1LL << (x - 1)) % mod;
    long long msb = (n - (1LL << x) + 1 + mod) % mod;
    return (ans + msb + solve(n - (1LL << x))) % mod;
}
