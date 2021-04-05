class Solution {
  public:
	bool exist(vector<vector<char>> &board, string word) {
		int m = board.size(), n = board[0].size();
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (existUtil(board, word, i, j, m, n, 0)) {
					return true;
				}
			}
		}
		return false;
	}

  private:

	vector<int> dx = {0, 0, 1, -1};
	vector<int> dy = {1, -1, 0, 0};

	bool existUtil(vector<vector<char>> &board, const string &word, int i, int j, int m, int n, int idx) {
		if (i < 0 || j < 0 || i >= m || j >= n || word[idx] != board[i][j]) {
			return false;
		}
		if (idx == word.size() - 1) {
			return true;
		}
		char temp = board[i][j];
		board[i][j] = '$';
		for (int k = 0; k < 4; k++) {
			int nx = i + dx[k];
			int ny = j + dy[k];
			if (existUtil(board, word, nx, ny, m, n, idx + 1)) {
				return true;
			}
		}
		board[i][j] = temp;
		return false;
	}
};