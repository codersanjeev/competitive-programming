vector<int> Solution::plusOne(vector<int> &A) {
	int n = A.size(), carry = 1;
	vector<int> ans(n, 0);
	for (int i = n - 1; i >= 0; i--) {
		int curr = A[i] + carry;
		ans[i] = curr % 10;
		carry = curr / 10;
	}
	if (carry == 0) {
		vector<int> newans;
		int i = 0;
		while (ans[i] == 0) {
			i++;
		}
		while (i < n) {
			newans.push_back(ans[i]);
			i++;
		}
		return newans;
	} else {
		vector<int> newans(n + 1);
		newans[0] = carry;
		for (int i = 0; i < n; i++) {
			newans[i + 1] = ans[i];
		}
		return newans;
	}
}