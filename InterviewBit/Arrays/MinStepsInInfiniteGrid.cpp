int Solution::coverPoints(vector<int> &A, vector<int> &B) {
	int n = A.size();
	int ans = 0;
	for (int i = 0; i < n - 1; i++) {
		int dx = abs(A[i + 1] - A[i]);
		int dy = abs(B[i + 1] - B[i]);
		ans += max(dx, dy);
	}
	return ans;
}