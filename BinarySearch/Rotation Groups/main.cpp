string getWord(const string &word) {
	vector<string> arr;
	string s = word;
	rotate(s.begin(), s.begin() + 1, s.end());
	arr.push_back(word);
	while (s != word) {
		arr.push_back(s);
		rotate(s.begin(), s.begin() + 1, s.end());
	}
	sort(arr.begin(), arr.end());
	return arr[0];
}

int solve(vector<string> &words) {
	unordered_set<string> ans;
	for (const auto &word : words) {
		string key = getWord(word);
		ans.insert(key);
	}
	return ans.size();
}