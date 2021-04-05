vector<string> getWords(const string &text) {
	istringstream s(text);
	string word;
	vector<string> ans;
	while (getline(s, word, ' ')) {
		ans.push_back(word);
	}
	return ans;
}

int solve(string text, string word0, string word1) {
	vector<string> words = getWords(text);
	int n = words.size(), ans = n + 1, j = -1, k = -1;
	for (int i = 0; i < n; i++) {
		if (words[i] == word0) {
			if (k != -1) {
				ans = min(ans, i - k - 1);
			}
			j = i;
		}
		if (words[i] == word1) {
			if (j != -1) {
				ans = min(ans, i - j - 1);
			}
			k = i;
		}
	}
	return (ans == n + 1 ? -1 : ans);
}