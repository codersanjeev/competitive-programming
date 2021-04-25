class Solution {
   public:
    int longestBeautifulSubstring(string word) {
        int n = word.size();
        vector<pair<char, int>> freq;
        vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        freq.push_back({word[0], 1});
        for (int i = 1; i < n; ++i) {
            if (word[i] == freq.back().first) {
                freq.back().second += 1;
            } else {
                freq.push_back({word[i], 1});
            }
        }
        int m = freq.size(), ans = 0, cnt = 0;
        for (int i = 0; i < m; ++i) {
            bool good = true;
            cnt = 0;
            for (int k = 0; k < 5; ++k) {
                if (i + k < m && freq[i + k].first == vowels[k]) {
                    cnt += freq[i + k].second;
                } else {
                    good = false;
                    break;
                }
            }
            if (good) ans = max(ans, cnt);
        }
        return ans;
    }
};