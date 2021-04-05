int Solution::adjacent(vector<vector<int>> &arr) {
	int n = arr[0].size();
	int A = 0, B = max(arr[0][0], arr[1][0]);
	for (int j = 1; j < n; j++) {
		int temp = max(A, B);
		B = A + max(arr[0][j], arr[1][j]);
		A = temp;
	}
	return max(A, B);
}
