class Solution {
   public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> seen;
        for (const auto& email : emails) {
            int index = findIndexOfAt(email);
            string pre = email.substr(0, index);
            string domain = email.substr(index + 1);
            // cout << "pre -> " << pre << "\n";
            string actualpre = findActualPre(pre);
            string actualEmail = actualpre + "@" + domain;
            seen.insert(actualEmail);
        }
        return seen.size();
    }

   private:
    int findIndexOfAt(const string& s) {
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '@') {
                return i;
            }
        }
        return n;
    }

    string findActualPre(const string& s) {
        string ans = "";
        for (const auto& ele : s) {
            if (ele == '.') {
                continue;
            }
            if (ele == '+') {
                return ans;
            }
            ans += ele;
        }
        return ans;
    }
};