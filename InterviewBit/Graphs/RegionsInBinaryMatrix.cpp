vector<int> dx = {-1, -1, -1, 0, 1, 1, 1, 0};
vector<int> dy = {-1, 0, 1, 1, 1, 0, -1, -1};

int dfs(const vector<vector<int>> &board, vector<vector<bool>> &visited, int i, int j, int n, int m) {
    visited[i][j] = true;
    int ans = 1;
    for (int k = 0; k < 8; k++) {
        int nx = i + dx[k];
        int ny = j + dy[k];
        if (nx >= 0 && ny >= 0 && nx < n && ny < m && visited[nx][ny] == false && board[nx][ny] == 1) {
            ans += dfs(board, visited, nx, ny, n, m);
        }
    }
    return ans;
}

int Solution::solve(vector<vector<int>> &board) {
    int n = board.size(), m = board[0].size(), ans = 0;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visited[i][j] == false && board[i][j] == 1) {
                ans = max(ans, dfs(board, visited, i, j, n, m));
            }
        }
    }
    return ans;
}
