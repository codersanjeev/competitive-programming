auto speedup = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return nullptr;
}();

class Solution {
  public:
	int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
		int n = beginWord.size();
		queue<pair<string, int>> q;
		set<string> words(wordList.begin(), wordList.end());
		set<string> visited;
		q.push({beginWord, 1});
		visited.insert(beginWord);
		if (words.count(endWord) == 0) {
			return 0;
		}
		while (!q.empty()) {
			auto curr = q.front();
			q.pop();
			string currWord = curr.first;
			int currSteps = curr.second;
			for (int i = 0; i < n; i++) {
				for (char ch = 'a'; ch <= 'z'; ch++) {
					string nextWord = currWord.substr(0, i) + ch + currWord.substr(i + 1);
					if (nextWord == endWord) {
						return currSteps + 1;
					}
					if (words.count(nextWord) > 0 && visited.count(nextWord) == 0) {
						q.push({nextWord, currSteps + 1});
						visited.insert(nextWord);
					}
				}
			}
		}
		return 0;
	}
};