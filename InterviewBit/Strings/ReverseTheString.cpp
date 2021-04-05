string Solution::solve(string s) {
	int n = s.size();
	if (n == 1 && s[0] != ' ') {
		return s;
	}
	string t = "";
	s += " ";
	n++;
	vector<string> ans;
	for (int i = 0; i < n; i++) {
		if (s[i] == ' ') {
			if (t != "") {
				ans.push_back(t);
				t = "";
			}
		} else {
			t += s[i];
		}
	}
	reverse(ans.begin(), ans.end());
	string finalAns = "";
	for (int i = 0; i < ans.size(); i++) {
		finalAns += ans[i];
		finalAns += " ";
	}
	return finalAns.substr(0, finalAns.size() - 1);
}
