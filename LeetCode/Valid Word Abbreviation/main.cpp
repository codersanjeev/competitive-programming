class Solution {
   public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0, j = 0, n = word.size(), m = abbr.size();
        while (i < n && j < m) {
            if (isdigit(abbr[j])) {
                if (abbr[j] == '0') {
                    return false;
                }
                int val = 0;
                while (j < m && isdigit(abbr[j])) {
                    val *= 10;
                    val += (abbr[j++] - '0');
                }
                i += val;
            } else if (word[i++] != abbr[j++]) {
                return false;
            }
        }
        return i == n && j == m;
    }
};