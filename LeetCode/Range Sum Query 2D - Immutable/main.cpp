class NumMatrix {
   public:
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        prefixSum = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                prefixSum[i][j] = matrix[i - 1][j - 1];
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; j++) {
                prefixSum[i][j] += prefixSum[i][j - 1];
            }
        }
        for (int j = 1; j <= m; ++j) {
            for (int i = 1; i <= n; ++i) {
                prefixSum[i][j] += prefixSum[i - 1][j];
            }
        }
    }

    int sumRegion(int si, int sj, int ei, int ej) {
        return prefixSum[ei + 1][ej + 1] - prefixSum[ei + 1][sj] - prefixSum[si][ej + 1] + prefixSum[si][sj];
    }

   private:
    vector<vector<int>> prefixSum;
};