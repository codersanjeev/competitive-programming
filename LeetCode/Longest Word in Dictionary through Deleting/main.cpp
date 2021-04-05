class Solution {
   public:
    string findLongestWord(string s, vector<string>& d) {
        string ans = "";
        for (const auto& word : d) {
            int j = 0, k = 0;
            while (j < s.size() && k < word.size()) {
                if (s[j] == word[k]) {
                    k++;
                }
                j++;
            }
            if (k == word.size() && ((ans.size() == word.size() && ans > word) || ans.size() < word.size())) {
                ans = word;
            }
        }
        return ans;
    }
};