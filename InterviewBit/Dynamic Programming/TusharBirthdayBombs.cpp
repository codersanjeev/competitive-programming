// unbounded knapsack
vector<int> Solution::solve(int W, vector<int> &wt) {
	vector<pair<int, int>> newWt;
	int prev = INT_MAX;
	for (int i = 0; i < wt.size(); i++) {
		if (wt[i] < prev) {
			newWt.push_back({i, wt[i]});
			prev = wt[i];
		}
	}
	int n = newWt.size();
	vector<int> ans;
	int i = 0, curr = newWt[n - 1].second;
	while (i < n) {
		if (W >= newWt[i].second && (1 + (W - newWt[i].second) / curr == W / curr)) {
			ans.push_back(newWt[i].first);
			W -= newWt[i].second;
		} else {
			i++;
		}
	}
	return ans;
}
