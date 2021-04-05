int f(const vector<int> &arr, int lo, int hi, int x) {
	if (hi >= lo) {
		int mid = lo + (hi - lo) / 2;
		if ((mid == 0 || x > arr[mid - 1]) && x == arr[mid]) {
			return mid;
		} else if (x > arr[mid]) {
			return f(arr, mid + 1, hi, x);
		} else {
			return f(arr, lo, mid - 1, x);
		}
	}
	return -1;
}

int g(const vector<int> &arr, int lo, int hi, int x) {
	if (hi >= lo) {
		int mid = lo + (hi - lo) / 2;
		if ((mid == arr.size() - 1 || x < arr[mid + 1]) && x == arr[mid]) {
			return mid;
		} else if (x < arr[mid]) {
			return g(arr, lo, mid - 1, x);
		} else {
			return g(arr, mid + 1, hi, x);
		}
	}
	return -1;
}

vector<int> Solution::searchRange(const vector<int> &arr, int x) {
	return vector<int> {f(arr, 0, arr.size() - 1, x), g(arr, 0, arr.size() - 1, x)};
}
