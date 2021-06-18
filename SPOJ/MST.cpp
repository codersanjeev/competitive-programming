#include <bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> parent;
    vector<int> rank;

   public:
    DSU(int n) {
        parent.resize(n, -1);
        rank.resize(n, 1);
    }

    int find(int u) {
        if (parent[u] == -1) {
            return u;
        } else {
            return parent[u] = find(parent[u]);
        }
    }

    void merge(int u, int v) {
        int a = find(u);
        int b = find(v);
        if (a != b) {
            if (rank[a] < rank[b]) {
                parent[a] = b;
                rank[b] += rank[a];
            } else {
                parent[b] = a;
                rank[a] += rank[b];
            }
        }
    }

    int numberOfConnectedComponents() {
        unordered_set<int> ans;
        for (int i = 0; i < parent.size(); ++i) {
            ans.insert(find(i));
        }
        return ans.size();
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m, u, v, w, ans = 0;
    cin >> n >> m;
    DSU *dsu = new DSU(n);
    vector<vector<int>> edges;
    while (m--) {
        cin >> u >> v >> w;
        edges.push_back({w, u - 1, v - 1});
        edges.push_back({w, v - 1, u - 1});
    }
    sort(edges.begin(), edges.end());
    for (const auto &edge : edges) {
        u = edge[1], v = edge[2], w = edge[0];
        if (dsu->find(u) != dsu->find(v)) {
            dsu->merge(u, v);
            ans += w;
        }
    }
    cout << ans;
    return 0;
}