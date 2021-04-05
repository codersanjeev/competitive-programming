vector<int> Solution::equal(vector<int> &arr) {
	unordered_map<int, pair<int, int>> mp;
	vector<int> ans;
	vector<pair<pair<int, int>, pair<int, int>>> ss;
	int n = arr.size();
	for (int i = 0 ; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int sum = arr[i] + arr[j];
			pair<int, int> t = {i, j};
			if (mp.find(sum) != mp.end()) {
				pair<int, int> x = mp[sum];
				if (x.first < t.first && x.second != t.first && x.second != t.second) {
					ss.push_back({x, t});
				}
			} else {
				mp[sum] = t;
			}
		}
	}
	if (ss.size() == 0) { return ans; }
	sort(ss.begin(), ss.end());
	ans.push_back(ss[0].first.first);
	ans.push_back(ss[0].first.second);
	ans.push_back(ss[0].second.first);
	ans.push_back(ss[0].second.second);
	return ans;
}
