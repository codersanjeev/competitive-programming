class Solution {
   public:
    int countBinarySubstrings(string s) {
        vector<int> g;
        int cnt = 1;
        for (int i = 1; i <= s.size(); ++i) {
            if (s[i] != s[i - 1]) {
                g.push_back(cnt);
                cnt = 1;
            } else {
                ++cnt;
            }
        }
        int ans = 0;
        for (int i = 1; i < g.size(); ++i) {
            ans += min(g[i - 1], g[i]);
        }
        return ans;
    }
};