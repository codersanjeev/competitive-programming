int f(const vector<int> &arr, int lo, int hi,  int x) {
	if (lo > hi) {
		return -1;
	}
	int mid = lo + (hi - lo) / 2;
	if (arr[mid] == x) {
		return mid;
	}
	if (arr[lo] <= arr[mid]) {
		if (x >= arr[lo] && x <= arr[mid]) {
			return f(arr, lo, mid - 1, x);
		}
		return f(arr, mid + 1, hi, x);
	}
	if (x >= arr[mid] && x <= arr[hi]) {
		return f(arr, mid + 1, hi, x);
	}
	return f(arr, lo, mid - 1, x);
}

int Solution::search(const vector<int> &arr, int x) {
	return f(arr, 0, arr.size() - 1, x);
}
