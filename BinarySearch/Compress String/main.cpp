string solve(string s) {
    string ans = "";
    for (const auto &ele : s) {
        if (ans.back() != ele) ans += ele;
    }
    return ans;
}