vector<vector<int>> solve(vector<vector<int>> &fractions) {
	set<pair<double, pair<int, int>>> st;
	for (const auto &fraction : fractions) {
		int x = fraction[0];
		int y = fraction[1];
		int g = __gcd(x, y);
		x /= g;
		y /= g;
		st.insert({(x * 1.0) / y, {x, y}});
	}
	vector<vector<int>> ans;
	for (const auto &ele : st) {
		ans.push_back({ele.second.first, ele.second.second});
	}
	for (auto &ele : ans) {
		if (ele[0] > 0 && ele[1] < 0) {
			ele[0] *= -1;
			ele[1] *= -1;
		}
	}
	return ans;
}