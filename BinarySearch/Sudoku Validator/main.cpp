bool solve(vector<vector<int>> &matrix) {
	int n = matrix.size(), m = matrix[0].size();
	if (n != 9 || m != 9) {
		return false;
	}
	set<int> idealSt;
	for (int i = 1; i <= 9; i++) {
		idealSt.insert(i);
	}
	for (int i = 0; i < 7; i += 3) {
		for (int j = 0; j < 7; j += 3) {
			set<int> st;
			for (int x = 0; x < 3; x++) {
				for (int y = 0; y < 3; y++) {
					st.insert(matrix[i + x][j + y]);
				}
			}
			if (st != idealSt) {
				return false;
			}
		}
	}
	for (int i = 0; i < 9; i++) {
		set<int> st;
		for (int j = 0; j < 9; j++) {
			st.insert(matrix[i][j]);
		}
		if (st != idealSt) {
			return false;
		}
	}
	for (int j = 0; j < 9; j++) {
		set<int> st;
		for (int i = 0; i < 9; i++) {
			st.insert(matrix[i][j]);
		}
		if (st != idealSt) {
			return false;
		}
	}
	return true;
}