class Solution {
   public:
    int hammingDistance(int x, int y) {
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            int a = x & (1 << i);
            int b = y & (1 << i);
            if (a != b) {
                ans++;
            }
        }
        return ans;
    }
};