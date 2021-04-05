
int Solution::sqrt(int A) {
	if (A == 0 || A == 1) {
		return A;
	}
	long L = 1, H = A, ans = 1;
	while (L <= H) {
		long M = L + (H - L) / 2;
		if ((M * M) == A) {
			return M;
		} else if ((M * M) > A) {
			H = M - 1;
		} else {
			ans = M;
			L = M + 1;
		}
	}
	return ans;
}