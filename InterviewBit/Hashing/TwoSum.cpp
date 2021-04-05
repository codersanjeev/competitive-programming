vector<int> Solution::twoSum(const vector<int> &arr, int target) {
	unordered_map<int, int> mp;
	int n = arr.size();
	for (int i = 0; i < n; i++) {
		if (mp.find(target - arr[i]) != mp.end()) {
			return {mp[target - arr[i]] + 1, i + 1};
		} else if (mp.find(arr[i]) == mp.end()) {
			mp[arr[i]] = i;
		}
	}
	return {};
}
