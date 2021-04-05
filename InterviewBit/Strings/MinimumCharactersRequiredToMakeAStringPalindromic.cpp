int lps(const string &s) {
    int n = s.size();
    vector<int> lps(n, 0);
    for (int i = 1; i < n; i++) {
        int j = lps[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = lps[j - 1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        lps[i] = j;
    }
    return lps[n - 1];
}

string reverseString(const string &s) {
    string t = s;
    reverse(t.begin(), t.end());
    return t;
}

int Solution::solve(string s) {
    int n = s.size();
    string t = s + "$" + reverseString(s);
    return n - lps(t);
}
