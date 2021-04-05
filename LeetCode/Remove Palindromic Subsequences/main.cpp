class Solution {
   public:
    int removePalindromeSub(string s) {
        if (s.empty()) {
            return 0;
        }
        if (valid(s)) {
            return 1;
        }
        return 2;
    }

   private:
    bool valid(const string &s) {
        string a = s;
        string b = s;
        reverse(b.begin(), b.end());
        if (a == b) {
            return true;
        }
        set<char> c(a.begin(), a.end());
        return c.size() == 1;
    }
};