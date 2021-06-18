#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, m, u, v, s;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<int> adj[n];
        while (m--) {
            cin >> u >> v;
            u--;
            v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        cin >> s;
        s--;
        queue<int> q;
        vector<bool> visited(n, false);
        vector<int> ans(n, -1);
        q.push(s);
        ans[s] = 0;
        visited[s] = true;
        while (!q.empty()) {
            u = q.front();
            q.pop();
            for (const auto &v : adj[u]) {
                if (visited[v] == false) {
                    q.push(v);
                    visited[v] = true;
                    ans[v] = ans[u] + 6;
                }
            }
        }
        for (const auto &ele : ans) {
            if (ele != 0)
                cout << ele << " ";
        }
        cout << "\n";
    }
    return 0;
}
