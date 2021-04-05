class Solution {
   public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size(), m = word2.size(), i = 0, j = 0, cnt = 0;
        string ans = "";
        while (i < n && j < m) {
            if (cnt % 2 == 0) {
                ans += word1[i];
                i++;
            } else {
                ans += word2[j];
                j++;
            }
            cnt++;
        }
        while (i < n) {
            ans += word1[i];
            i++;
        }
        while (j < m) {
            ans += word2[j];
            j++;
        }
        return ans;
    }
};