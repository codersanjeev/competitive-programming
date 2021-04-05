class Solution {
   public:
    string longestNiceSubstring(string s) {
        int n = s.size();
        string ans = "";
        int mx = INT_MIN;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                string t = s.substr(i, j - i + 1);
                if (isNice(t) && j - i + 1 > mx) {
                    mx = j - i + 1;
                    ans = t;
                }
            }
        }
        return ans;
    }

   private:
    bool isNice(const string &s) {
        set<char> st(s.begin(), s.end());
        for (const auto &ele : st) {
            if (islower(ele)) {
                char ch = (char)toupper(ele);
                if (st.count(ch) == 0) {
                    return false;
                }
            } else {
                char ch = (char)tolower(ele);
                if (st.count(ch) == 0) {
                    return false;
                }
            }
        }
        return true;
    }
};