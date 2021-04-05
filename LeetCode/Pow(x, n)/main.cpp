class Solution {
   public:
    double myPow(double x, int N) {
        long n = (long)N;
        if (n == 0) return 1.0;
        if (n < 0) {
            n *= -1LL;
            x = 1.0 / x;
        }
        double temp = myPow(x, n / 2);
        double ans = temp * temp;
        return n % 2 == 0 ? ans : ans * x;
    }
};