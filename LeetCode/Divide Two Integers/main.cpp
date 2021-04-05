class Solution {
   public:
    int divide(int dividend, int divisor) {
        if (dividend == 0) return 0;
        if (divisor == 0) return INT_MAX;
        long long ans = exp(log(labs(dividend)) - log(labs(divisor)));
        if (dividend < 0 ^ divisor < 0) ans = -ans;
        return ans > INT_MAX ? INT_MAX : ans;
    }
};