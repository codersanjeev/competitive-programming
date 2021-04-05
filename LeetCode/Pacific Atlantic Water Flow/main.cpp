class Solution {
  public:
	vector<vector<int>> pacificAtlantic(vector<vector<int>> &matrix) {
		if (matrix.empty()) {
			return {};
		}
		int n = matrix.size(), m = matrix[0].size();
		vector<vector<bool>> pacific(n, vector<bool>(m, false));
		vector<vector<bool>> atlantic(n, vector<bool>(m, false));
		for (int i = 0; i < n; i++) {
			dfs(matrix, pacific, i, 0, n, m);
			dfs(matrix, atlantic, i, m - 1, n, m);
		}
		for (int j = 0; j < m; j++) {
			dfs(matrix, pacific, 0, j, n, m);
			dfs(matrix, atlantic, n - 1, j, n, m);
		}
		vector<vector<int>> ans;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (pacific[i][j] && atlantic[i][j]) {
					ans.push_back({i, j});
				}
			}
		}
		return ans;
	}
  private:

	vector<pair<int, int>> delta = {{0, 1}, {0, -1}, {1, 0}, { -1, 0}};

	void dfs(const vector<vector<int>> &matrix, vector<vector<bool>> &visited, int i, int j, int n, int m) {
		if (i < 0 || j < 0 || i >= n || j >= m || visited[i][j] == true) {
			return;
		}
		visited[i][j] = true;
		for (const auto &d : delta) {
			int nx = i + d.first;
			int ny = j + d.second;
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && matrix[nx][ny] >= matrix[i][j] && visited[nx][ny] == false) {
				dfs(matrix, visited, nx, ny, n, m);
			}
		}
	}
};