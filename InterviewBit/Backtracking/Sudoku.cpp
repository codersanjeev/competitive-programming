vector<vector<char>> board;

bool isValid(int x, int y, char c) {
	for (int j = 0; j < 9; j++)
		if (board[x][j] == c) {
			return false;
		}
	for (int i = 0; i < 9; i++)
		if (board[i][y] == c) {
			return false;
		}
	int a = (x / 3) * 3;
	int b = (y / 3) * 3;
	for (int i = a; i < a + 3; i++) {
		for (int j = b; j < b + 3; j++) {
			if (board[i][j] == c) {
				return false;
			}
		}
	}
	return true;
}

bool backtrack(int x, int y) {
	int nextRow = -1;
	int nextColumn = -1;
	bool flagA = false;
	bool flagB = false;
	for (int i = y + 1; i < 9; i++) {
		if (board[x][i] == '.') {
			nextRow = x;
			nextColumn = i;
			flagA = true;
			break;
		}
	}
	if (!flagA) {
		for (int i = x + 1; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (board[i][j] == '.') {
					nextRow = i;
					nextColumn = j;
					flagB = true;
					break;
				}
			}
			if (flagB) {
				break;
			}
		}
	}
	for (int i = 1; i <= 9; i++) {
		char temp = '0' + i;
		if (isValid(x, y, temp)) {
			board[x][y] = temp;
			if (nextRow == -1) {
				return true;
			}
			bool result = backtrack(nextRow, nextColumn);
			if (result) {
				return true;
			}
			board[x][y] = '.';
		}
	}
	return false;
}

void Solution::solveSudoku(vector<vector<char>> &A) {
	board = A;
	bool flag = false;
	int start, end;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (board[i][j] == '.') {
				start = i;
				end = j;
				flag = true;
				break;
			}
		}
		if (flag) {
			break;
		}
	}
	backtrack(start, end);
	A = board;
}
