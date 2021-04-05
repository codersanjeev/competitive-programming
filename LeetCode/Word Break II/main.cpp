class Solution {
  public:
	vector<string> wordBreak(string s, vector<string> &wordDict) {
		unordered_set<string> wordDictionary(wordDict.begin(), wordDict.end());
		return wordBreakUtil(s, wordDictionary);
	}

  private:

	unordered_map<string, vector<string>> dp;

	vector<string> wordBreakUtil(string s, unordered_set<string> &dictionary) {
		if (dp.find(s) != dp.end()) {
			return dp[s];
		}
		vector<string> ans;
		for (int i = 1; i <= s.size(); i++) {
			string left = s.substr(0, i);
			if (dictionary.count(left) > 0) {
				string right = s.substr(i);
				if (right.empty()) {
					ans.push_back(left);
				} else {
					vector<string> rightAnswer = wordBreakUtil(right, dictionary);
					for (const auto &rightAns : rightAnswer) {
						ans.push_back(left + " " + rightAns);
					}
				}
			}
		}
		return dp[s] = ans;
	}
};