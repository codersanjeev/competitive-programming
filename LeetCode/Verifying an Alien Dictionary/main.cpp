class Solution {
   public:
    bool isAlienSorted(vector<string> &words, string order) {
        vector<int> mappedOrder(26, 0);
        for (int i = 0; i < 26; ++i) {
            mappedOrder[order[i] - 'a'] = i;
        }
        for (auto &word : words) {
            for (auto &ch : word) {
                ch = mappedOrder[ch - 'a'];
            }
        }
        return is_sorted(words.begin(), words.end());
    }
};