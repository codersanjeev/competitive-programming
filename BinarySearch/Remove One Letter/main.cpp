bool solve(string s0, string s1) {
    int n = s0.size(), m = s1.size();
    if (n < m) return false;
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (s0[i++] == s1[j]) {
            ++j;
        }
    }
    return (j == m && n - j == 1);
}