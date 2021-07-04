class Solution {
   private:
    const long long mod = 1e9 + 7;

    long long binpow(long long x, long long y) {
        x %= mod;
        long long ans = 1LL;
        while (y > 0) {
            if (y % 2 == 1) ans = (ans * x) % mod;
            x = (x * x) % mod;
            y /= 2;
        }
        return ans;
    }

   public:
    int countGoodNumbers(long long n) {
        long long x = n / 2LL;
        long long y = n - x;
        return (binpow(4, x) * binpow(5, y)) % mod;
    }
};