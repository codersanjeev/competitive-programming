int Solution::bulbs(vector<int> &arr) {
	int ans = 0;
	int n = arr.size();
	for (int i = 0; i < n; i++) {
		if ((ans % 2 == 0 && arr[i] == 0) || (ans % 2 == 1 && arr[i] == 1)) {
			ans++;
		}
	}
	return ans;
}
