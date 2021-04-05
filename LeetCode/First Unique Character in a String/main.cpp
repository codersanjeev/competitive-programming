class Solution {
   public:
    int firstUniqChar(string s) {
        vector<int> seen(256, 0);
        int n = s.size();
        for (int i = 0; i < n; i++) {
            seen[s[i] - 'a']++;
        }
        int index = -1;
        for (int i = 0; i < n; i++) {
            if (seen[s[i] - 'a'] == 1) {
                index = i;
                break;
            }
        }
        return index;
    }
};