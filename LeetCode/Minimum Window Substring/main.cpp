class Solution {
   public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mapTwo, mapOne;
        for (const auto &ch : t) {
            mapTwo[ch]++;
        }
        int matchCount = 0, i = -1, j = -1, n = s.size(), m = t.size();
        string ans = "";
        while (true) {
            bool flagOne = false, flagTwo = false;
            while (i < n - 1 && matchCount < m) {
                i++;
                mapOne[s[i]]++;
                if (mapOne[s[i]] <= mapTwo[s[i]]) {
                    matchCount++;
                }
                flagOne = true;
            }

            while (j < i && matchCount == m) {
                string temp = s.substr(j + 1, i - j);
                if (ans.size() == 0 || ans.size() > temp.size()) {
                    ans = temp;
                }
                j++;
                mapOne[s[j]]--;
                if (mapOne[s[j]] < mapTwo[s[j]]) {
                    matchCount--;
                }
                flagTwo = true;
            }
            if (flagOne == false && flagTwo == false) {
                break;
            }
        }
        return ans;
    }
};