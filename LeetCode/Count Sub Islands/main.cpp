class Solution {
   private:
    vector<vector<int>> grid1, grid2;
    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};
    int n, m;

    int dfs(int i, int j) {
        if (i < 0 || j < 0 || i >= n || j >= m || grid2[i][j] == 0) {
            return -1;
        }
        if (grid1[i][j] == 0) return 0;
        grid2[i][j] = 0;
        int res = 1;
        for (int k = 0; k < 4; ++k) {
            if (dfs(i + dx[k], j + dy[k]) == 0) {
                res = 0;
            }
        }
        return res;
    }

   public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        this->grid1 = grid1;
        this->grid2 = grid2;
        this->n = grid2.size();
        this->m = grid2[0].size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (dfs(i, j) == 1) ++ans;
            }
        }
        return ans;
    }
};