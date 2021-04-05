class Solution {
   public:
    vector<vector<string>> partition(string s) {
        if (s.empty()) {
            return ans;
        }
        solve(s, 0);
        return ans;
    }

   private:
    vector<vector<string>> ans;
    vector<string> curr;

    void solve(string &s, int index) {
        if (index == s.size()) {
            ans.push_back(curr);
            return;
        }
        for (int i = index; i < s.size(); i++) {
            if (isPalindrome(s, index, i)) {
                curr.push_back(s.substr(index, i - index + 1));
                solve(s, i + 1);
                curr.pop_back();
            }
        }
    }

    bool isPalindrome(const string &s, int i, int j) {
        while (i < j) {
            if (s[i++] != s[j--]) {
                return false;
            }
        }
        return true;
    }
};