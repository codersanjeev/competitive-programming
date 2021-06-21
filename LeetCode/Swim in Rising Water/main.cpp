class Solution {
   private:
    vector<vector<int>> grid;
    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};

    bool ok(vector<vector<bool>> &visited, int t, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid.size() || visited[i][j] || grid[i][j] > t) {
            return false;
        }
        visited[i][j] = true;
        for (int k = 0; k < 4; ++k) {
            ok(visited, t, i + dx[k], j + dy[k]);
        }
        return visited.back().back();
    }

   public:
    int swimInWater(vector<vector<int>> &grid) {
        this->grid = grid;
        int n = grid.size();
        int lo = 0, hi = n * n, ans = n * n;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            vector<vector<bool>> visited(n, vector<bool>(n, false));
            if (ok(visited, mid, 0, 0)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};