class Solution {
   public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        int n = pid.size();
        const int N = 1e5 + 1;
        vector<int> adj[N];
        for (int i = 0; i < n; i++) {
            int u = pid[i];
            int v = ppid[i];
            adj[v].push_back(u);
        }
        vector<bool> visited(N, false);
        dfs(adj, kill, visited);
        vector<int> ans;
        for (int i = 0; i < N; i++) {
            if (visited[i]) {
                ans.push_back(i);
            }
        }
        return ans;
    }

    void dfs(vector<int> adj[], int u, vector<bool>& visited) {
        visited[u] = true;
        for (const auto& v : adj[u]) {
            dfs(adj, visited, v);
        }
    }
};