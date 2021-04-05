const int N = 1e5 + 1;
vector<int> adj[N];
vector<bool> visited(N, false);
int n, ans;

int dfs(int u) {
    visited[u] = true;
    int components = 0;
    for (const auto &v : adj[u]) {
        if (visited[v] == false) {
            int subtreeComponents = dfs(v);
            if (subtreeComponents % 2 == 0) {
                ans++;
            } else {
                components += subtreeComponents;
            }
        }
    }
    return components + 1;
}

int Solution::solve(int A, vector<vector<int>> &edges) {
    n = A;
    ans = 0;
    for (auto &ele : adj) {
        ele.clear();
    }
    for (int i = 0; i < N; i++) {
        visited[i] = false;
    }
    for (const auto &edge : edges) {
        adj[edge[0] - 1].push_back(edge[1] - 1);
        adj[edge[1] - 1].push_back(edge[0] - 1);
    }
    dfs(0);
    return ans;
}
