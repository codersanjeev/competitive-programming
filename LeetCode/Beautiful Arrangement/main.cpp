class Solution {
  public:

	int ans = 0;

	void solveUtil(int n, int pos, vector<bool> &visited) {
		if (pos > n) {
			ans++;
			return;
		}
		for (int i = 1; i <= n; i++) {
			if (!visited[i] && (i % pos == 0 || pos % i == 0)) {
				visited[i] = true;
				solveUtil(n, pos + 1, visited);
				visited[i] = false;
			}
		}
	}

	int countArrangement(int n) {
		if (n == 0) {
			return 0;
		}
		ans = 0;
		vector<bool> visited(n + 1, false);
		solveUtil(n, 1, visited);
		return ans;
	}
};