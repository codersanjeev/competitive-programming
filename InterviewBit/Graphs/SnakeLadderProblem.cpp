int snakesAndLadders(vector<int> &arr) {
    int n = arr.size();
    vector<bool> visited(n, false);
    queue<pair<int, int>> q;
    q.push({0, 0});
    while (!q.empty()) {
        auto curr = q.front();
        q.pop();
        int u = curr.first;
        int d = curr.second;
        if (u == n - 1) {
            return d;
        }
        visited[u] = true;
        for (int i = 1; i <= 6; i++) {
            int ni = u + i;
            if (ni < n && arr[ni] != -1) {
                ni = arr[ni] - 1;
            }
            if (ni >= n) {
                continue;
            }
            if (ni == n - 1 || visited[ni] == false) {
                q.push({ni, d + 1});
            }
        }
    }
    return -1;
}

int Solution::snakeLadder(vector<vector<int>> &A, vector<vector<int>> &B) {
    vector<int> board(100, -1);
    for (const auto &edge : A) {
        int u = edge[0];
        int v = edge[1];
        board[u - 1] = v;
    }
    for (const auto &edge : B) {
        int u = edge[0];
        int v = edge[1];
        board[u - 1] = v;
    }
    return snakesAndLadders(board);
}
