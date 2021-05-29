class Solution {
   public:
    int countGoodSubstrings(string s) {
        int n = s.size(), ans = 0;
        for (int i = 0; i < n - 2; i++) {
            string t = s.substr(i, 3);
            set<char> temp(t.begin(), t.end());
            if (temp.size() == 3) ++ans;
        }
        return ans;
    }
};