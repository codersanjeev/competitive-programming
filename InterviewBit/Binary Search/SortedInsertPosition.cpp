int Solution::searchInsert(vector<int> &arr, int x) {
	int lo = 0, hi = arr.size() - 1;
	while (lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		if (arr[mid] == x || (mid == 0 && arr[mid] > x) || (mid > 0 && arr[mid] > x && arr[mid - 1] < x)) {
			return mid;
		}
		if (x > arr[mid]) {
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}
	return arr.size();
}
