class DSU {
    vector<int> parent;
    vector<int> rank;

   public:
    DSU(int n) {
        parent.resize(n, -1);
        rank.resize(n, 1);
    }

    int find(int u) {
        return parent[u] == -1 ? u : parent[u] = find(parent[u]);
    }

    bool merge(int u, int v) {
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
            return true;
        }
        return false;
    }
};

class Solution {
   public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        DSU *dsu = new DSU(edges.size());
        for (int i = 0; i < edges.size(); ++i) {
            if (!dsu->merge(edges[i][0] - 1, edges[i][1] - 1)) {
                return edges[i];
            }
        }
        return {};
    }
};