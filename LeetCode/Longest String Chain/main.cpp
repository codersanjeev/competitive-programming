class Solution {
  public:

	// x is pre of y?
	bool isPredecessor(const string &x, const string &y) {
		int n = x.size(), m = y.size();
		if (m - n != 1) {
			return false;
		}
		if (y.substr(1) == x || y.substr(0, n) == x) {
			return true;
		}
		for (int i = 0; i < m - 1; i++) {
			string curr = y.substr(0, i) + y.substr(i + 1);
			if (curr == x) {
				return true;
			}
		}
		return false;
	}

	int longestStrChain(vector<string> &words) {
		int n = words.size();
		if (n < 2) {
			return n;
		}
		sort(words.begin(), words.end(), [](const string & x, const string & y) {
			int a = x.size(), b = y.size();
			return a < b;
		});
		vector<int> dp(n, 1);
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (isPredecessor(words[j], words[i])) {
					dp[i] = max(dp[i], 1 + dp[j]);
				}
			}
		}
		return *max_element(dp.begin(), dp.end());
	}
};