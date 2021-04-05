string Solution::solve(string s) {
    string ans = "";
    queue<char> q;
    vector<int> seen(256, 0);
    int n = s.size();
    for (int i = 0; i < n; i++) {
        seen[s[i]]++;
        q.push(s[i]);
        while (!q.empty() && seen[q.front()] > 1) {
            q.pop();
        }
        ans += (q.empty() ? '#' : q.front());
    }
    return ans;
}
