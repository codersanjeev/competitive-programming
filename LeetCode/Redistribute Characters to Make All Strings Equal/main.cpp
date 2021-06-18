class Solution {
   public:
    bool makeEqual(vector<string> &words) {
        vector<int> freq(26, 0);
        for (const auto &word : words) {
            for (const auto &ch : word) freq[ch - 'a']++;
        }
        for (const auto &ele : freq) {
            if (ele % words.size() != 0) return false;
        }
        return true;
    }
};