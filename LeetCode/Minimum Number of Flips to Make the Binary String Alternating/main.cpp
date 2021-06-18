class Solution {
   public:
    int minFlips(string s) {
        int n = s.size();
        vector<int> arr(2 * n);
        for (int i = 0; i < 2 * n; ++i) {
            arr[i] = (i % 2) ^ (s[i % n] - '0');
        }
        int zeros = 0, ones = 0;
        for (int i = 0; i < n; ++i) {
            if (arr[i] == 0)
                ++zeros;
            else
                ++ones;
        }
        int i = 0, j = n, ans = n;
        while (j < 2 * n) {
            ans = min({ans, zeros, ones});
            if (arr[i++] == 0)
                --zeros;
            else
                --ones;
            if (arr[j++] == 0)
                ++zeros;
            else
                ++ones;
        }
        return ans;
    }
};