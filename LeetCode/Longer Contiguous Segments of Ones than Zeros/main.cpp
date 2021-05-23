class Solution {
   public:
    bool checkZeroOnes(string s) {
        auto count = [](const string& s, char ch) -> int {
            vector<int> dp(s.size(), 0);
            if (s[0] == ch) dp[0] = 1;
            for (int i = 1; i < s.size(); ++i) {
                if (s[i] == ch) {
                    dp[i] = s[i] == s[i - 1] ? dp[i - 1] + 1 : 1;
                }
            }
            return *max_element(dp.begin(), dp.end());
        };
        return count(s, '1') > count(s, '0');
    }
};