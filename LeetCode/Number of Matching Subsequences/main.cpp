class Solution {
   public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> index(s.size() + 1, vector<int>(26, s.size()));
        for (int i = s.size() - 1; i >= 0; --i) {
            for (int j = 0; j < 26; ++j) {
                index[i][j] = index[i + 1][j];
            }
            index[i][s[i] - 'a'] = i;
        }
        int ans = 0;
        for (const auto& word : words) {
            int curr = 0;
            bool good = true;
            for (const auto& ch : word) {
                curr = index[curr][ch - 'a'];
                if (curr == s.size()) {
                    good = false;
                    break;
                }
                ++curr;
            }
            if (good) ++ans;
        }
        return ans;
    }
};
