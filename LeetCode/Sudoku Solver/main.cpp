class Solution {
  public:
	void solveSudoku(vector<vector<char>> &board) {
		solveSudokuUtil(board, 0, 0);
		board = ans;
	}

  private:
	vector<vector<char>> ans;

	bool isValid(const vector<vector<char>> &board, int x, int y, char val) {
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

	void solveSudokuUtil(vector<vector<char>> &board, int x, int y) {
		if (x == 9) {
			ans = board;
			return;
		}
		int nx = x, ny = y;
		if (y == 8) {
			nx = x + 1;
			ny = 0;
		} else {
			nx = x;
			ny = y + 1;
		}
		if (board[x][y] != '.') {
			solveSudokuUtil(board, nx, ny);
		} else {
			for (char ch = '1'; ch <= '9'; ch++) {
				if (isValid(board, x, y, ch)) {
					board[x][y] = ch;
					solveSudokuUtil(board, nx, ny);
					board[x][y] = '.';
				}
			}
		}
	}
};