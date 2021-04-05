int Solution::solve(vector<string> &arr) {
	sort(arr.begin(), arr.end());
	int lo = 0, hi = arr.size() - 1;
	while (hi - lo >= 2) {
		int mid = lo + (hi - lo) / 2;
		double curr = stod(arr[lo]) + stod(arr[mid]) + stod(arr[hi]);
		if (curr > 2) {
			hi--;
		} else if (curr < 1) {
			lo++;
		} else {
			return 1;
		}
	}
	return 0;
}
