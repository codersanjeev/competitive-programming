int Solution::maxProfit(const vector<int> &stocks) {
	int mn = INT_MAX, ans = 0;
	for (auto &ele : stocks) {
		if (ele < mn) {
			mn = ele;
		} else if (ele - mn > ans) {
			ans = ele - mn;
		}
	}
	return ans;
}
