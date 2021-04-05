int solve(vector<int> &prices) {
	if (prices.empty()) {
		return 0;
	}
	int ans = 0, n = prices.size(), curr = prices[0];
	for (int i = 1; i < n; i++) {
		if (prices[i] > curr) {
			ans += (prices[i] - curr);
			curr = prices[i];
		} else {
			curr = prices[i];
		}
	}
	return ans;
}