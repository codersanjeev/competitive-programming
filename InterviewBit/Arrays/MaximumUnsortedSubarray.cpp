vector<int> Solution::subUnsort(vector<int> &arr) {
	int n = arr.size();
	int lo = -1, hi = -1;
	int temp = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] < temp) {
			hi = i;
		}
		temp = max(temp, arr[i]);
	}
	temp = arr[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		if (arr[i] > temp) {
			lo = i;
		}
		temp = min(temp, arr[i]);
	}
	return lo == -1 ? vector<int> {lo} : vector<int> {lo, hi};
}
