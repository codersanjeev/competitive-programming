vector<vector<string>> Solution::findLadders(string beginWord, string endWord, vector<string> &wordsList) {
	if (beginWord == endWord) {
		vector<vector<string>> ans = {{beginWord}};
		return ans;
	}
	unordered_set<string> wordList;
	for (auto ele : wordsList) {
		wordList.insert(ele);
	}
	vector<vector<string>> ans;
	queue<vector<string>> paths;
	paths.push({beginWord});
	int level = 1;
	int minLevel = INT_MAX;
	unordered_set<string> visited;
	while (!paths.empty()) {
		vector<string> path = paths.front();
		paths.pop();
		if (path.size() > level) {
			for (string w : visited) { wordList.erase(w); }
			visited.clear();
			if (path.size() > minLevel) {
				break;
			} else {
				level = path.size();
			}
		}
		string last = path.back();
		for (int i = 0; i < last.size(); ++i) {
			string news = last;
			for (char c = 'a'; c <= 'z'; ++c) {
				news[i] = c;
				if (wordList.find(news) != wordList.end()) {
					vector<string> newpath = path;
					newpath.push_back(news);
					visited.insert(news);
					if (news == endWord) {
						minLevel = level;
						ans.push_back(newpath);
					} else {
						paths.push(newpath);
					}
				}
			}
		}
	}
	return ans;
}
