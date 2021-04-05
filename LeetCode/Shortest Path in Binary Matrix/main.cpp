class Solution {
   public:
    vector<int> dx = {0, 1, 1, 1, -1, -1, -1, 0};
    vector<int> dy = {-1, -1, 0, 1, -1, 0, 1, 1};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0) {
            return -1;
        }
        queue<pair<int, int>> q;
        grid[0][0] = 1;
        q.push({0, 0});
        while (!q.empty()) {
            auto cell = q.front();
            q.pop();
            int i = cell.first;
            int j = cell.second;
            int dist = grid[i][j];
            if (i == n - 1 && j == n - 1) {
                return dist;
            }
            for (int k = 0; k < 8; k++) {
                int ni = i + dx[k];
                int nj = j + dy[k];
                if (ni < 0 || nj < 0 || ni >= n || nj >= n || grid[ni][nj] != 0) {
                    continue;
                }
                q.push({ni, nj});
                grid[ni][nj] = dist + 1;
            }
        }
        return -1;
    }
};