class Solution {
  public:
	int largestSubmatrix(vector<vector<int>> &matrix) {
		int n = matrix.size(), m = matrix[0].size(), ans = 0;
		for (int j = 0; j < m; j++) {
			int curr = 0;
			for (int i = 0; i < n; i++) {
				if (matrix[i][j] == 0) {
					curr = 0;
				} else {
					curr++;
				}
				matrix[i][j] = curr;
			}
		}
		for (auto &row : matrix) {
			sort(row.begin(), row.end());
			for (int j = m - 1; j >= 0; j--) {
				ans = max(ans, (m - j) * row[j]);
			}
		}
		return ans;
	}
};