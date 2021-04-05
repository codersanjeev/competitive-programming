bool isValid(vector<string> &board, string &s, int row, int col, int n) {
	if (s[col] == 'Q') {
		return false;
	}
	int j = col, k = 1;
	for (int i = row - 1; i >= 0; i--) {
		if (j + k < n && board[i][j + k] == 'Q') {
			return false;
		}
		if (j - k >= 0 && board[i][j - k] == 'Q') {
			return false;
		}
		k++;
	}
	return true;
}

void backtrack(vector<vector<string>> &ans, vector<string> &board, int row, int n, string &s) {
	if (row == n) {
		ans.push_back(board);
		return;
	}
	for (int column = 0; column < n; column++) {
		if (isValid(board, s, row, column, n)) {
			board[row][column] = 'Q';
			s[column] = 'Q';
			backtrack(ans, board, row + 1, n, s);
			board[row][column] = '.';
			s[column] = '.';
		}
	}
}

vector<vector<string>> Solution::solveNQueens(int n) {
	vector<vector<string>> ans;
	vector<string> board(n, string(n, '.'));
	string s(n, '.');
	backtrack(ans, board, 0, n, s);
	return ans;
}
