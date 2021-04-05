class Solution {
  public:
	int numDecodings(string s) {
		int n = s.size();
		vector<int> dp(n + 1, 0);
		dp[0] = 1;
		dp[1] = s[0] == '0' ? 0 : 1;
		for (int i = 2; i <= n; i++) {
			if (s[i - 1] != '0') {
				dp[i] += dp[i - 1];
			}
			int num = toInt(s[i - 2], s[i - 1]);
			if (num >= 10 && num <= 26) {
				dp[i] += dp[i - 2];
			}
		}
		return dp.back();
	}

  private:
	int toInt(const char &a, const char &b) {
		int x = a - '0';
		int y = b - '0';
		return x * 10 + y;
	}
};