int lcs(const string &s, const string &t) {
    int n = s.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][n];
}

int lps(const string &s) {
    string t = s;
    reverse(t.begin(), t.end());
    return lcs(s, t);
}

bool isPalindrome(const string &s, int i, int j) {
    while (i < j) {
        if (s[i] != s[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int Solution::solve(string A) {
    int start = 0, end = A.size() - 1;
    while (start < end) {
        if (A[start] != A[end]) {
            if (isPalindrome(A, start + 1, end) || isPalindrome(A, start, end - 1))
                return 1;
            else
                return 0;
        }
        start++;
        end--;
    }
    return 1;
}
