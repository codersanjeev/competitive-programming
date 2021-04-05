vector<vector<int>> Solution::anagrams(const vector<string> &arr) {
	unordered_map<string, vector<int>> mp;
	vector<vector<int>> ans;
	int n = arr.size();
	for (int i = 0; i < n; i++) {
		auto curr = arr[i];
		sort(curr.begin(), curr.end());
		mp[curr].push_back(i + 1);
	}
	for (auto ele : mp) {
		ans.push_back(ele.second);
	}
	return ans;
}
