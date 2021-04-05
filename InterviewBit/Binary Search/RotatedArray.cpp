
int Solution::findMin(const vector<int> &A) {
	int n = A.size();
	if (A[0] <= A[n - 1]) {
		return A[0];
	}
	int L = 0, R = n - 1;
	while (L <= R) {
		int M = L + (R - L) / 2;
		if (A[M] >= A[M + 1]) {
			return A[M + 1];
		} else if (A[L] <= A[M]) {
			L = M + 1;
		} else {
			R = M - 1;
		}
	}
	return A[n - 1];
}