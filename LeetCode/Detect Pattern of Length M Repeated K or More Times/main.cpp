auto speedup = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return nullptr;
}();

class Solution {
  public:
	bool containsPattern(vector<int>& a, int m, int k) {
		int cnt = 0;
		for (int i = 0; i + m < a.size() && cnt < m * (k - 1); ++i)
			cnt = a[i] == a[i + m] ? cnt + 1 : 0;
		return cnt == m * (k - 1);
	}
};