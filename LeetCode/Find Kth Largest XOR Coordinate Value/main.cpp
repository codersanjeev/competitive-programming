class Solution {
  public:
	int kthLargestValue(vector<vector<int>> &matrix, int k) {
		int n = matrix.size(), m = matrix[0].size();
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < m; j++) {
				matrix[i][j] ^= matrix[i - 1][j];
			}
		}
		for (int j = 1; j < m; j++) {
			for (int i = 0; i < n; i++) {
				matrix[i][j] ^= matrix[i][j - 1];
			}
		}
		vector<int> ans;
		for (const auto &row : matrix) {
			for (const auto &ele : row) {
				ans.push_back(ele);
			}
		}
		sort(ans.begin(), ans.end(), greater<int>());
		return ans[k - 1];
	}
};