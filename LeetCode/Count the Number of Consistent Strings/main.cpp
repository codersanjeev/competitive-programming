class Solution {
  public:
	int countConsistentStrings(string allowed, vector<string> &words) {
		set<char> st(allowed.begin(), allowed.end());
		int ans = 0;
		for (const auto &ele : words) {
			bool good = true;
			for (const auto &ch : ele) {
				if (st.count(ch) == 0) {
					good = false;
					break;
				}
			}
			if (good) {
				ans++;
			}
		}
		return ans;
	}
};