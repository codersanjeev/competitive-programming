class Solution {
   private:
    bool isGood(const vector<vector<int>> &grid, int x, int y, int len) {
        set<int> st;
        for (int i = x; i < x + len; ++i) {
            int curr = 0;
            for (int j = y; j < y + len; ++j) curr += grid[i][j];
            st.insert(curr);
        }
        for (int j = y; j < y + len; ++j) {
            int curr = 0;
            for (int i = x; i < x + len; ++i) curr += grid[i][j];
            st.insert(curr);
        }
        if (st.size() > 1) return false;
        int i = x, j = y, curr = 0;
        while (i < x + len && j < y + len) {
            curr += grid[i][j];
            ++i;
            ++j;
        }
        st.insert(curr);
        if (st.size() > 1) return false;
        i = x, j = y + len - 1, curr = 0;
        while (i < x + len && j >= y) {
            curr += grid[i][j];
            ++i;
            --j;
        }
        st.insert(curr);
        return st.size() == 1;
    }

    int solve(const vector<vector<int>> &grid, int n, int m) {
        for (int len = n; len >= 2; --len) {
            for (int i = 0; i + len <= n; ++i) {
                for (int j = 0; j + len <= m; ++j) {
                    if (isGood(grid, i, j, len)) return len;
                }
            }
        }
        return 1;
    }

   public:
    int largestMagicSquare(vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size();
        if (n < m) {
            return solve(grid, n, m);
        } else {
            vector<vector<int>> arr(m, vector<int>(n));
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    arr[j][i] = grid[i][j];
                }
            }
            return solve(arr, m, n);
        }
    }
};