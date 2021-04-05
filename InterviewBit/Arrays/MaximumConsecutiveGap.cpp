vector<int> arr;

int Solution::maximumGap(const vector<int> &A) {
	arr = A;
	sort(arr.begin(), arr.end());
	int n = arr.size();
	if (n < 2) {
		return 0;
	}
	int ans = INT_MIN;
	for (int i = 0; i < n - 1; i++) {
		ans = max(ans, arr[i + 1] - arr[i]);
	}
	return ans;
}
