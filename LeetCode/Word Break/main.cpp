class Solution {
  public:
	bool wordBreak(string s, vector<string> &wordDict) {
		unordered_set<string> wordDictionary(wordDict.begin(), wordDict.end());
		return wordBreakUtil(s, wordDictionary);
	}

  private:

	unordered_map<string, bool> dp;

	bool wordBreakUtil(string s, unordered_set<string> &dictionary) {
		if (dp.find(s) != dp.end()) {
			return dp[s];
		}
		int n = s.size();
		if (n == 0) {
			return true;
		}
		for (int i = 1; i <= n; i++) {
			if (dictionary.count(s.substr(0, i)) > 0 && wordBreakUtil(s.substr(i), dictionary)) {
				return dp[s] = true;
			}
		}
		return dp[s] = false;
	}
};