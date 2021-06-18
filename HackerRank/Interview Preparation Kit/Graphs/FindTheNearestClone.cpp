#include <bits/stdc++.h>
using namespace std;

int findShortestPath(vector<int> adj[], vector<bool> &visited, int u, int id, vector<int> &colors) {
    visited[u] = true;
    int ans = colors.size();
    for (const auto &v : adj[u]) {
        if (visited[v] == false) {
            int curr = 1;
            if (colors[v] == id) {
                return curr;
            }
            curr += findShortestPath(adj, visited, v, id, colors);
            ans = min(ans, curr);
        }
    }
    return ans;
}

int main() {
    int n, m, u, v, id;
    cin >> n >> m;
    vector<int> adj[n];
    while (m--) {
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> colors(n);
    map<int, int> mp;
    for (auto &ele : colors) {
        cin >> ele;
        mp[ele]++;
    }
    cin >> id;
    vector<bool> visited(n, false);
    if (mp[id] < 2) {
        cout << -1;
    } else {
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (colors[i] == id) {
                ans = min(ans, findShortestPath(adj, visited, i, id, colors));
            }
        }
        cout << ans;
    }
    return 0;
}