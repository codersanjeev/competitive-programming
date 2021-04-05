vector<int> Solution::allFactors(int A) {
	vector<int> ans;
	for (int i = 1; i * i <= A; i++) {
		if (A % i == 0) {
			ans.push_back(i);
			if (i != A / i) {
				ans.push_back(A / i);
			}
		}
	}
	sort(ans.begin(), ans.end());
	return ans;
}