bool solve(string s0, string s1) {
    if (s0.size() != s1.size()) return false;
    s0 += s0;
    return s0.find(s1) != string::npos;
}