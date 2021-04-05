vector<vector<int>> ans;

bool isValid(const vector<vector<int>> &board, int x, int y, int val) {
	for (int i = 0; i < 9; i++) {
		if (board[i][y] == val || board[x][i] == val) {
			return false;
		}
	}
	int sx = 3 * (x / 3), sy = 3 * (y / 3);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[sx + i][sy + j] == val) {
				return false;
			}
		}
	}
	return true;
}

void solveUtil(vector<vector<int>> &board, int i, int j) {
	int x = i, y = j;
	if (x == 9) {
		ans = board;
		return;
	}
	if (j == 8) {
		x = i + 1;
		y = 0;
	} else {
		x = i;
		y = j + 1;
	}
	if (board[i][j] != 0) {
		solveUtil(board, x, y);
	} else {
		for (int po = 1; po <= 9; po++) {
			if (isValid(board, i, j, po)) {
				board[i][j] = po;
				solveUtil(board, x, y);
				board[i][j] = 0;
			}
		}
	}
}

vector<vector<int>> solve(vector<vector<int>> &board) {
	solveUtil(board, 0, 0);
	return ans;
}