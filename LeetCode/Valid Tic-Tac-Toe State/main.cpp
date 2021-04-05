class Solution {
  public:
	bool validTicTacToe(vector<string> &board) {
		bool xWon = false, oWon = false;
		int numX = 0, numO = 0;
		for (string s : board) {
			if (s == "XXX") {
				xWon = true;
			}
			if (s == "OOO") {
				oWon = true;
			}
			for (char c : s) {
				if (c == 'X') {
					numX++;
				} else if (c == 'O') {
					numO++;
				}
			}
		}
		if (numO > numX || numX - numO > 1 || (xWon && oWon)) {
			return false;
		}
		for (int j = 0; j < 3; j++) {
			string temp = "";
			for (int i = 0; i < 3; i++) {
				temp += board[i][j];
			}
			if (temp == "XXX") {
				xWon = true;
			}
			if (temp == "OOO") {
				oWon = true;
			}
		}
		if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') {
			xWon = true;
		}
		if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') {
			oWon = true;
		}
		if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X') {
			xWon = true;
		}
		if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O') {
			oWon = true;
		}
		if (xWon && oWon) {
			return false;
		}
		if (xWon && numX - numO == 0) {
			return false;
		}
		if (oWon && numX - numO == 1) {
			return false;
		}
		return true;
	}
};