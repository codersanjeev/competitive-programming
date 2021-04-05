int Solution::climbStairs(int n) {
	if (n < 3) {
		return n;
	}
	vector<int> ans(n + 1);
	ans[1] = 1;
	ans[2] = 2;
	for (int i = 3; i <= n; i++) {
		ans[i] = ans[i - 1] + ans[i - 2];
	}
	return ans[n];
}
