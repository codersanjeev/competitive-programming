void Solution::arrange(vector<int> &A) {
	int n = A.size();
	for (int i = 0; i < n; i++) {
		int x = A[i];
		int y = A[A[i]];
		int code = x + (y % n) * n;
		A[i] = code;
	}
	for (int i = 0; i < n; i++) {
		A[i] /= n;
	}
}
