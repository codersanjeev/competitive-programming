int Solution::maxp3(vector<int> &arr) {
	sort(arr.begin(), arr.end());
	int n = arr.size();
	return max(arr[0] * arr[1] * arr[n - 1], arr[n - 3] * arr[n - 2] * arr[n - 1]);
}
