class Solution {
   public:
    int compress(vector<char>& chars) {
        int n = (int)chars.size();
        string ans = "";
        ans += chars[0];
        int curr = 1;
        for (int i = 1; i < n; i++) {
            if (ans.back() != chars[i]) {
                if (curr > 1) {
                    ans += to_string(curr);
                }
                ans += chars[i];
                curr = 1;
            } else {
                curr++;
            }
        }
        if (curr > 1) {
            ans += to_string(curr);
        }
        int m = (int)ans.size();
        if (m <= n) {
            for (int i = 0; i < m; i++) {
                chars[i] = ans[i];
            }
        }
        return m;
    }
};