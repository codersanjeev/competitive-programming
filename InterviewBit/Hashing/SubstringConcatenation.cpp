int findUtil(string s, const vector<string> &words) {
	int n = words.size();
	for (int i = 0; i < n; i++)
		if (words.at(i) == s) {
			return i;
		}
	return -1;
}

vector<int> Solution::findSubstring(string s, const vector<string> &words) {
	if (s.empty() || words.empty())
		return {};
	vector<int> output ;
	int length = words.size() * words.at(0).size();
	int wordLength = words.at(0).size();
	if (length > s.size())
		return {};
	vector<int> visited(words.size(), 0);
	int start = 0;
	unordered_map<string, int> map;
	for (int i = 0; i < words.size(); i++) {
		map[words.at(i)] += 1;
	}
	for (int i = 0; i < s.size(); i++) {
		if (i - start == length) {
			output.push_back(start);
		} else {
			string str = s.substr(i, wordLength);
			int index = findUtil(str, words);
			if (index != -1) {
				if (visited.at(index) < map[str]) {
					visited.at(index) += 1;
					i += wordLength - 1;
					continue;
				}
			}
		}
		for (int j = 0; j < visited.size(); j++) {
			visited[j] = 0;
		}
		i = start;
		start = i + 1;
	}
	if (s.size() - start == length) {
		output.push_back(start);
	}
	return output ;
}
