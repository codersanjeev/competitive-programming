class Solution {
   public:
    bool checkOnesSegment(string s) {
        string ans = "";
        ans += s[0];
        for (int i = 1; i < s.size(); i++) {
            if (ans.back() != s[i]) {
                ans += s[i];
            }
        }
        int cnt = 0;
        for (const auto &ele : ans) {
            if (ele == '1') {
                cnt++;
            }
        }
        return cnt <= 1;
    }
};