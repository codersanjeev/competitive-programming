int Solution::singleNumber(const vector<int> &arr) {
	int ans = arr[0];
	int n = arr.size();
	for (int i = 1; i < n; i++) {
		ans ^= arr[i];
	}
	return ans;
}
