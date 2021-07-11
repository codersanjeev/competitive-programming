class Solution {
   public:
    int nearestExit(vector<vector<char>> &maze, vector<int> &entrance) {
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};
        int m = maze.size(), n = maze[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<vector<int>> q;
        q.push({entrance[0], entrance[1], 0});
        visited[entrance[0]][entrance[1]] = true;
        auto isSafe = [&](int i, int j) -> bool {
            return i >= 0 && i < m && j >= 0 && j < n;
        };
        auto isBoundary = [&](int i, int j) -> bool {
            return i == 0 || i == m - 1 || j == 0 || j == n - 1;
        };
        while (!q.empty()) {
            vector<int> curr = q.front();
            q.pop();
            for (int k = 0; k < 4; ++k) {
                int nx = curr[0] + dx[k], ny = curr[1] + dy[k];
                if (!isSafe(nx, ny) || visited[nx][ny] || maze[nx][ny] == '+') {
                    continue;
                }
                if (isBoundary(nx, ny) && maze[nx][ny] == '.' && !visited[nx][ny]) {
                    return curr[2] + 1;
                }
                if (maze[nx][ny] == '.' && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    q.push({nx, ny, curr[2] + 1});
                }
            }
        }
        return -1;
    }
};