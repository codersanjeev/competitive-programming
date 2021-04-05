string solve(string sentence) {
	stack<string> st;
	string word = "";
	for (const auto &ele : sentence) {
		if (ele == ' ') {
			st.push(word);
			word = "";
		} else {
			word += ele;
		}
	}
	st.push(word);
	string ans = "";
	while (!st.empty()) {
		auto curr = st.top();
		st.pop();
		ans += curr;
		ans += " ";
	}
	ans.pop_back();
	return ans;
}