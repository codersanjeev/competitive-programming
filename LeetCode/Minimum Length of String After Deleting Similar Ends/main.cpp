class Solution {
   public:
    int minimumLength(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j && s[i] == s[j]) {
            char ch = s[i];
            while (i <= j && s[i] == ch) {
                i++;
            }
            while (i <= j && s[j] == ch) {
                j--;
            }
        }
        return max(0, j - i + 1);
    }
};