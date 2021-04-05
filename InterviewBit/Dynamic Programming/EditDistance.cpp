int mini(int x, int y, int z) {
	return min(x, min(y, z));
}

int Solution::minDistance(string x, string y) {
	int m = x.size();
	int n = y.size();
	int arr[m + 1][n + 1];
	arr[0][0] = 1;
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == 0) {
				arr[i][j] = j;
			} else if (j == 0) {
				arr[i][j] = i;
			} else if (x[i - 1] == y[j - 1]) {
				arr[i][j] = arr[i - 1][j - 1];
			} else {
				int insert = 1 + arr[i][j - 1];
				int replace = 1 + arr[i - 1][j - 1];
				int dlt = 1 + arr[i - 1][j];
				arr[i][j] = mini(insert, replace, dlt);
			}
		}
	}
	return arr[m][n];
}