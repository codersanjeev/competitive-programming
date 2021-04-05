int Solution::diffPossible(const vector<int> &arr, int k) {
	int n = arr.size();
	if (n <= 1) {
		return 0;
	}
	unordered_map<int, int> mp;
	for (auto ele : arr) {
		if (mp[ele + k] != 0 || mp[ele - k] != 0) {
			return 1;
		}
		mp[ele] = 1;
	}
	return 0;
}
