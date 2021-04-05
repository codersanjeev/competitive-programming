int Solution::maxArr(vector<int> &A) {
	int n = A.size();
	int x1 = INT_MIN;
	int x2 = INT_MIN;
	int y1 = INT_MAX;
	int y2 = INT_MAX;
	int ans = INT_MIN;
	for (int i = 1; i <= n; i++) {
		x1 = max(x1, A[i - 1] - i);
		x2 = max(x2, A[i - 1] + i);
		y1 = min(y1, A[i - 1] - i);
		y2 = min(y2, A[i - 1] + i);
		ans = max(ans, x1 - y1);
		ans = max(ans, x2 - y2);
	}
	return ans;
}