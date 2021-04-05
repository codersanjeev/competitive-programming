int Solution::maxArea(vector<int> &arr) {
	int lo = 0, hi = arr.size() - 1, ans = 0;
	while (lo < hi) {
		ans = max(ans, min(arr[lo], arr[hi]) * (hi - lo));
		if (arr[lo] < arr[hi]) {
			lo++;
		} else {
			hi--;
		}
	}
	return ans;
}
