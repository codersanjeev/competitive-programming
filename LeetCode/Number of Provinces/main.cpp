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

class Solution {
   public:
    int findCircleNum(vector<vector<int>> &isConnected) {
        int n = isConnected.size();
        DSU *dsu = new DSU(n);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isConnected[i][j] == 1) dsu->merge(i, j);
            }
        }
        return dsu->numberOfConnectedComponents();
    }
};