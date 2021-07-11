class Solution {
   public:
    int countTriples(int n) {
        int ans = 0;
        for (int a = 1; a <= n; ++a) {
            for (int b = 1; b <= n; ++b) {
                for (int c = 1; c <= n; ++c) {
                    if (a * a + b * b == c * c) {
                        ++ans;
                    }
                }
            }
        }
        return ans;
    }
};