class Solution {
  public:
	int balancedStringSplit(string s) {
		int n = s.size();
		vector<int> pre(n, 1);
		for (int i = 0; i < n; i++) {
			if (s[i] == 'R') {
				pre[i] = -1;
			}
		}
		for (int i = 1; i < n; i++) {
			pre[i] += pre[i - 1];
		}
		int ans = 0;
		for (const auto &ele : pre) {
			if (ele == 0) {
				ans++;
			}
		}
		return ans;
	}
};