vector<string> splitWord(const string &s) {
	istringstream ss(s);
	string t;
	vector<string> ans;
	while (getline(ss, t, ' ')) {
		ans.push_back(t);
	}
	return ans;
}

bool solve(string s, string pattern) {
	vector<string> words = splitWord(s);
	if (words.size() != pattern.size()) {
		return false;
	}
	unordered_map<string, int> ab, ba;
	int n = words.size();
	for (int i = 0; i < n; i++) {
		string ch(1, pattern[i]);
		string word = words[i];
		if (ab[word] != ba[ch]) {
			return false;
		}
		ab[word] = ba[ch] = i + 1;
	}
	return true;
}