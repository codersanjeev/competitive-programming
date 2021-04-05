vector<string> Solution::letterCombinations(string s) {
	vector<string> ans;
	string mp[10] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
	ans.push_back("");
	for (int i = 0; i < s.size(); i++) {
		vector<string> temp;
		string ch = mp[s[i] - '0'];
		for (int c = 0; c < ch.size(); c++) {
			for (int j = 0; j < ans.size(); j++) {
				temp.push_back(ans[j] + ch[c]);
			}
		}
		ans = temp;
	}
	sort(ans.begin(), ans.end());
	return ans;
}
