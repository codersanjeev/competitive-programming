vector<int> Solution::dNums(vector<int> &arr, int k) {
	int n = arr.size();
	vector<int> ans;
	if (k > n) {
		return ans;
	}
	int curr = 0;
	unordered_map<int, int> mp;
	for (int i = 0; i < k; i++) {
		if (mp[arr[i]] == 0) {
			curr++;
		}
		mp[arr[i]]++;
	}
	ans.push_back(curr);
	for (int i = k; i < n; i++) {
		if (mp[arr[i - k]] == 1) {
			curr--;
		}
		mp[arr[i - k]]--;
		if (mp[arr[i]] == 0) {
			curr++;
		}
		mp[arr[i]]++;
		ans.push_back(curr);
	}
	return ans;
}
