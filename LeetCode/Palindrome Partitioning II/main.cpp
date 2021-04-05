class Solution {
   public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n + 1);
        vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));
        for (int i = 0; i <= n; i++) {
            dp[i] = i - 1;
        }
        int len = 1;
        while (len < n) {
            int i = len;
            while (i >= 0) {
                if (s[i] == s[len] && (len - i < 2 || isPalindrome[i + 1][len - 1])) {
                    isPalindrome[i][len] = true;
                    dp[len + 1] = min(dp[len + 1], 1 + dp[i]);
                }
                i--;
            }
            len++;
        }
        return dp[n];
    }
};