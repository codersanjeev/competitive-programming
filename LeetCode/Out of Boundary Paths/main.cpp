auto speedup = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return nullptr;
}();

class Solution {
  public:
	int findPaths(int m, int n, int N, int i0, int j0) {
		vector<vector<vector<uint>>> dp(N + 1, vector<vector<uint>>(m, vector<uint>(n, 0)));
		auto paths = [&](int k, int i, int j) { return (i < 0 || i >= m || j < 0 || j >= n) ? 1 : dp[k][i][j]; };
		for (int k = 1; k <= N; k++) {
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					dp[k][i][j] = paths(k - 1, i - 1, j) + paths(k - 1, i + 1, j) + paths(k - 1, i, j - 1) + paths(k - 1, i, j + 1);
					dp[k][i][j] %= 1000000007;
				}
			}
		}
		return dp[N][i0][j0];
	}
};