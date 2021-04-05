vector<int> Solution::findPerm(const string s, int n) {
	vector<int> ans;
	int mn = 1, mx = n;
	for (int i = 0; i < n - 1; i++) {
		if (s[i] == 'I') {
			ans.push_back(mn);
			mn++;
		} else {
			ans.push_back(mx);
			mx--;
		}
	}
	ans.push_back(mx);
	return ans;
}