class Solution {
   public:
    bool isIsomorphic(string s, string t) {
        vector<int> a(256, 0), b(256, 0);
        for (int i = 0; i < s.size(); ++i) {
            int x = (int)s[i];
            int y = (int)t[i];
            if (a[x] != b[y]) return false;
            a[x] = b[y] = i + 1;
        }
        return true;
    }
};