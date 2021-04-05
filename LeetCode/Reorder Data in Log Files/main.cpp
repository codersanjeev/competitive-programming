class Solution {
   public:
    vector<string> reorderLogFiles(vector<string> &logs) {
        stable_sort(logs.begin(), logs.end(), [](const string &s1, const string &s2) {
            int p1 = s1.find(' '), p2 = s2.find(' ');
            if (!isdigit(s1[p1 + 1]) && !isdigit(s2[p2 + 1])) {
                if (s1.substr(p1 + 1) == s2.substr(p2 + 1)) {
                    return s1.substr(0, p1 + 1) < s2.substr(0, p2 + 1);
                } else {
                    return s1.substr(p1 + 1) < s2.substr(p2 + 1);
                }
            } else {
                if (!isdigit(s1[p1 + 1])) return true;
                return false;
            }
            return false;
        });
        return logs;
    }
};