class Solution {
   private:
    vector<long> dp;
    const long mod = 1e9 + 7;

    long numDecodingsHelper(const string &s, long index) {
        if (index == s.size()) return 1;
        if (dp[index] != -1) return dp[index];
        long ans = 0;
        if (s[index] == '*')
            ans = (ans + 9 * numDecodingsHelper(s, index + 1)) % mod;
        else if (s[index] > '0')
            ans = (ans + numDecodingsHelper(s, index + 1)) % mod;
        if (index + 1 < s.size()) {
            char a = s[index], b = s[index + 1];
            if (a == '2' && b == '*') {
                ans = (ans + 6 * numDecodingsHelper(s, index + 2)) % mod;
            } else if (a == '1' && b == '*') {
                ans = (ans + 9 * numDecodingsHelper(s, index + 2)) % mod;
            } else if (a == '*' && b == '*') {
                ans = (ans + 15 * numDecodingsHelper(s, index + 2)) % mod;
            } else if (a == '2' && b <= '6') {
                ans = (ans + numDecodingsHelper(s, index + 2)) % mod;
            } else if (a == '1') {
                ans = (ans + numDecodingsHelper(s, index + 2)) % mod;
            } else if (a == '*' && b <= '6') {
                ans = (ans + 2 * numDecodingsHelper(s, index + 2)) % mod;
            } else if (a == '*') {
                ans = (ans + numDecodingsHelper(s, index + 2)) % mod;
            }
        }
        return dp[index] = ans;
    }

   public:
    int numDecodings(string s) {
        dp.resize(s.size(), -1);
        return numDecodingsHelper(s, 0);
    }
};