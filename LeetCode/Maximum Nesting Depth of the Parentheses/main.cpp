class Solution {
  public:
	int maxDepth(string s) {
		int ans = 0, curr = 0;
		for (const auto &ch : s) {
			if (ch == '(') {
				curr++;
			} else if (ch == ')') {
				curr--;
			}
			ans = max(ans, curr);
		}
		return ans;
	}
};