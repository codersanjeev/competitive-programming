class Solution {
   public:
    bool confusingNumber(int N) {
        int n = N, m = 0;
        while (N > 0) {
            int d = N % 10;
            if (mp[d] == -1) {
                return false;
            }
            m *= 10;
            N /= 10;
            m += mp[d];
        }
        return m != n;
    }

   private:
    vector<int> mp = {0, 1, -1, -1, -1, -1, 9, -1, 8, 6};
};