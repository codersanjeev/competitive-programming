int solve(string s) {
	stack<char> st;
	int ans = 0;
	for (const auto &ele : s) {
		if (ele == '(') {
			st.push(ele);
		} else {
			if (st.empty()) {
				ans++;
			} else {
				st.pop();
			}
		}
	}
	return ans + st.size();
}