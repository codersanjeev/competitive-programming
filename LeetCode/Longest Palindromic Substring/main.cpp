class Solution {
  public:
	string longestPalindrome(string s) {
		string ans = "";
		int len = 0, n = s.size();
		for (int i = 0; i < n; i++) {
			for (const auto &x : { -1, 0}) {
				int L = i + x, R = i;
				while (L >= 0 && R < n && s[L] == s[R]) {
					int curr = R - L + 1;
					if (curr > len) {
						len = curr;
						ans = s.substr(L, len);
					}
					L--;
					R++;
				}
			}
		}
		return ans;
	}
};