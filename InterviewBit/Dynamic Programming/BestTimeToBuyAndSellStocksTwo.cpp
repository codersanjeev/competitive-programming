int Solution::maxProfit(const vector<int> &stocks) {
	int ans = 0, n = stocks.size();
	for (int i = 1; i < n; i++)
		if (stocks[i] > stocks[i - 1]) {
			ans += (stocks[i] - stocks[i - 1]);
		}
	return ans;
}
