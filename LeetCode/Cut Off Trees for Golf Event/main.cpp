class Solution {
   public:
    int cutOffTree(vector<vector<int>>& forest) {
        if (forest.empty() || forest[0].empty()) return 0;
        int m = forest.size(), n = forest[0].size();
        vector<vector<int>> trees;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (forest[i][j] > 1) trees.push_back({forest[i][j], i, j});
            }
        }
        sort(trees.begin(), trees.end());
        int ans = 0;
        for (int i = 0, cur_row = 0, cur_col = 0; i < trees.size(); i++) {
            int step = next_step(forest, cur_row, cur_col, trees[i][1], trees[i][2]);
            if (step == -1) return -1;
            ans += step;
            cur_row = trees[i][1];
            cur_col = trees[i][2];
        }
        return ans;
    }

   private:
    int next_step(vector<vector<int>>& forest, int sr, int sc, int er, int ec) {
        if (sr == er && sc == ec) return 0;
        int m = forest.size(), n = forest[0].size();
        queue<pair<int, int>> myq;
        myq.push({sr, sc});
        vector<vector<int>> visited(m, vector<int>(n, 0));
        visited[sr][sc] = 1;
        int step = 0;
        vector<int> dir = {-1, 0, 1, 0, -1};
        while (!myq.empty()) {
            step++;
            int sz = myq.size();
            for (int i = 0; i < sz; i++) {
                int row = myq.front().first, col = myq.front().second;
                myq.pop();
                for (int i = 0; i < 4; i++) {
                    int r = row + dir[i], c = col + dir[i + 1];
                    if (r < 0 || r >= m || c < 0 || c >= n || visited[r][c] == 1 || forest[r][c] == 0) continue;
                    if (r == er && c == ec) return step;
                    visited[r][c] = 1;
                    myq.push({r, c});
                }
            }
        }
        return -1;
    }
};