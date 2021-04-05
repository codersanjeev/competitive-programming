int Solution::numRange(vector<int> &arr, int l, int r) {
	int i = 0, j = 0, sum = 0, ans = 0, n = arr.size();
	while (i < n) {
		sum += arr[j];
		if ((sum >= l) && (sum <= r)) {
			ans++;
			j++;
		} else if (sum < l) {
			j++;
		} else if (sum > r) {
			i++;
			j = i;
			sum = 0;
		}
		if (j == n) {
			sum = 0;
			i++;
			j = i;
		}
	}
	return ans;
}
