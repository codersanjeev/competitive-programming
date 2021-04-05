bool checkRow(const vector<string> &board, int i) {
	set<char> st;
	for (int j = 0; j < 9; j++) {
		if (st.find(board[i][j]) != st.end()) {
			return false;
		}
		if (board[i][j] != '.') {
			st.insert(board[i][j]);
		}
	}
	return true;
}

bool checkColumn(const vector<string> &board, int j) {
	set<char> st;
	for (int i = 0; i < 9; i++) {
		if (st.find(board[i][j]) != st.end()) {
			return false;
		}
		if (board[i][j] != '.') {
			st.insert(board[i][j]);
		}
	}
	return true;
}

bool checkBox(const vector<string> &board, int i, int j) {
	set<char> st;
	for (int s = 0; s < 3; s++) {
		for (int e = 0; e < 3; e++) {
			if (st.find(board[s + i][e + j]) != st.end()) {
				return false;
			}
			if (board[s + i][e + j] != '.') {
				st.insert(board[s + i][e + j]);
			}
		}
	}
	return true;
}

bool isValid(const vector<string> &board, int i, int j) {
	return checkRow(board, i) && checkColumn(board, j) && checkBox(board, i - i % 3, j - j % 3);
}

int Solution::isValidSudoku(const vector<string> &board) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (!isValid(board, i, j)) {
				return 0;
			}
		}
	}
	return 1;
}
