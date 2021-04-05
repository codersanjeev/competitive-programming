int Solution::firstMissingPositive(vector<int> &arr) {
	int n = arr.size();
	vector<bool> flag(n + 2, false);
	for (auto ele : arr) {
		if (ele > 0 && ele < n + 2) {
			flag[ele] = true;
		}
	}
	for (int i = 1; i <= n + 1; i++) {
		if (!flag[i]) {
			return i;
		}
	}
}
