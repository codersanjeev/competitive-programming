class Solution {
   private:
    vector<vector<int>> ans;
    vector<int> adj[100001];
    vector<bool> visited;
    vector<int> in;
    vector<int> low;
    int timer = 0;

    void dfs(int u, int p = -1) {
        visited[u] = true;
        in[u] = low[u] = timer;
        ++timer;
        for (const auto &v : adj[u]) {
            if (v == p) continue;
            if (visited[v]) {
                low[u] = min(low[u], in[v]);
            } else {
                dfs(v, u);
                if (low[v] > in[u]) {
                    ans.push_back({u, v});
                }
                low[u] = min(low[u], low[v]);
            }
        }
    }

   public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &edges) {
        visited.resize(n, false);
        in.resize(n);
        low.resize(n);
        for (const auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        dfs(0);
        return ans;
    }
};