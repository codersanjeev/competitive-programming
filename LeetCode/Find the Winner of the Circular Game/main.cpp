class Solution {
   public:
    int findTheWinner(int n, int k) {
        int result = 0;
        for (int i = 2; i <= n; i++) {
            result = (k + result) % i;
        }
        return result + 1;
    }
};