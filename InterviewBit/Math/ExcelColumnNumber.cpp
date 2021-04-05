int Solution::titleToNumber(string A) {
	int n = A.size(), ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		int factor = pow(26, n - i - 1);
		ans += (factor * (A[i] - 'A' + 1));
	}
	return ans;
}