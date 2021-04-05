vector<int> Solution::solve(int p1, int p2, int p3, int k) {
	vector<int> ans;
	if (k == 0)
		return ans;
	set<int> st;
	st.insert(p1);
	st.insert(p2);
	st.insert(p3);
	while (!st.empty()) {
		int curr = *st.begin();
		st.erase(st.begin());
		ans.push_back(curr);
		if (ans.size() == k)
			break;
		st.insert(curr * p1);
		st.insert(curr * p2);
		st.insert(curr * p3);
	}
	return ans;
}
