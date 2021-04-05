int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
	int i = A.size() - 1;
	int j = B.size() - 1;
	int k = C.size() - 1;
	int ans = max({abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i])});
	while (i >= 0 && j >= 0 && k >= 0) {
		int curr = max({abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i])});
		ans = min(ans, curr);
		int mx = max({A[i], B[j], C[k]});
		if (mx == A[i]) {
			i--;
		} else if (mx == B[j]) {
			j--;
		} else {
			k--;
		}
	}
	return ans;
}
