class Solution {
   public:
    int numDistinctIslands(vector<vector<int>> &grid) {
        unordered_set<string> islands;
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    string island = "";
                    dfs(grid, i, j, n, m, island, 'o');
                    grid[i][j] = 0;
                    islands.insert(island);
                }
            }
        }
        return islands.size();
    }

   private:
    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};
    vector<char> dir = {'r', 'l', 'd', 'u'};

    void dfs(vector<vector<int>> &grid, int i, int j, int n, int m, string &island, char direction) {
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0) {
            return;
        }
        island.push_back(direction);
        grid[i][j] = 0;
        for (int k = 0; k < 4; k++) {
            dfs(grid, i + dx[k], j + dy[k], n, m, island, dir[k]);
        }
        island.push_back('b');
    }
};