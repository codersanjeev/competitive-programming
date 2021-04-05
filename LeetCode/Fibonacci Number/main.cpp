class Solution {
public:
    int fib(int n) {
        return (n < 2 ? n : fib(n - 1) + fib(n - 2));
    }
};