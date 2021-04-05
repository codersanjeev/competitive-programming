int Solution::longestSubsequenceLength(const vector<int> &arr) {
	int n = arr.size();
	if (n < 2) {
		return n;
	}
	vector<int> lr(n, 1), rl(n, 1);
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i] && lr[i] < 1 + lr[j]) {
				lr[i] = 1 + lr[j];
			}
		}
	}
	for (int i = n - 2; i >= 0; i--) {
		for (int j = n - 1; j > i; j--) {
			if (arr[i] > arr[j] && rl[i] < 1 + rl[j]) {
				rl[i] = 1 + rl[j];
			}
		}
	}
	int ans = INT_MIN;
	for (int i = 0; i < n; i++) {
		ans = max(ans, lr[i] + rl[i] - 1);
	}
	return ans;
}
