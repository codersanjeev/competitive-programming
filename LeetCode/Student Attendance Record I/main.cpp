class Solution {
  public:
	bool checkRecord(string s) {
		int a = 0, n = s.size();
		for (const auto &ch : s) {
			if (ch == 'A') {
				a++;
			}
		}
		if (a > 1) {
			return false;
		}
		for (int i = 2; i < n; i++) {
			if (s.substr(i - 2, 3) == "LLL") {
				return false;
			}
		}
		return true;
	}
};