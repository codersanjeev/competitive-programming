class Solution {
   public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size(), prev = INT_MIN / 2;
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            if (s[i] == c) {
                prev = i;
            }
            ans[i] = i - prev;
        }
        prev = INT_MAX / 2;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == c) {
                prev = i;
            }
            ans[i] = min(ans[i], prev - i);
        }
        return ans;
    }
};