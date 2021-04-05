int Solution::findMinXor(vector<int> &arr) {
	sort(arr.begin(), arr.end());
	int ans = INT_MAX;
	int n = arr.size();
	for (int i = 0; i < n - 1; i++) {
		ans = min(ans, arr[i] ^ arr[i + 1]);
	}
	return ans;
}
