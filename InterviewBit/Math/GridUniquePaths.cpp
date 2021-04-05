
int uniquePathsUtil(int i, int j, int x, int y) {
	if (i == x && j == y) {
		return 1;
	}
	if (i > x || j > y) {
		return 0;
	}
	return uniquePathsUtil(i + 1, j, x, y) + uniquePathsUtil(i, j + 1, x, y);
}

int Solution::uniquePaths(int A, int B) {
	return uniquePathsUtil(1, 1, A, B);
}
