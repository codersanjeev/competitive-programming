string Solution::reverseString(string s) {
	stack<char> st;
	int n = s.size();
	for (int i = 0; i < n; i++) {
		st.push(s[i]);
	}
	string ans = "";
	while (!st.empty()) {
		ans += st.top();
		st.pop();
	}
	return ans;
}
