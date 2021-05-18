class Solution {
   private:
    bool isPredecessor(const string &x, const string &y) {
        if (y.size() - x.size() != 1) return false;
        if (y.substr(1) == x || y.substr(0, x.size()) == x) return true;
        for (int i = 0; i < y.size() - 1; ++i) {
            if (y.substr(0, i) + y.substr(i + 1) == x) return true;
        }
        return false;
    }

   public:
    int longestStrChain(vector<string> &words) {
        if (words.size() < 2) return words.size();
        sort(words.begin(), words.end(), [](const string &x, const string &y) {
            return x.size() < y.size();
        });
        vector<int> dp(words.size(), 1);
        for (int i = 1; i < words.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (isPredecessor(words[j], words[i])) dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};