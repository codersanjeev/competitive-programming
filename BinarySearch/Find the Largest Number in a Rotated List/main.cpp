int solve(vector<int> &arr) {
	int n = arr.size();
	if (n == 1 || arr[n - 1] >= arr[0]) {
		return arr.back();
	}
	int lo = 0, hi = n - 1;
	while (lo < hi) {
		int mid = lo + (hi - lo) / 2;
		if (mid + 1 < n && arr[mid] > arr[mid + 1]) {
			return arr[mid];
		} else if (arr[lo] > arr[mid]) {
			hi = mid;
		} else {
			lo = mid;
		}
	}
	return -1;
}