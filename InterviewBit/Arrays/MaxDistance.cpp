int Solution::maximumGap(const vector<int> &arr) {
	int n = arr.size();
	vector<int> maxArr(n), minArr(n);
	maxArr[n - 1] = arr[n - 1];
	minArr[0] = arr[0];
	for (int i = 1; i < n; i++) {
		minArr[i] = min(minArr[i - 1], arr[i]);
	}
	for (int i = n - 2; i >= 0; i--) {
		maxArr[i] = max(maxArr[i + 1], arr[i]);
	}
	int i = 0, j = 0, ans = 0;
	while (i < n && j < n) {
		if (minArr[i] <= maxArr[j]) {
			ans = max(ans, j - i);
			j++;
		} else {
			i++;
		}
	}
	return ans;
}
