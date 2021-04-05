auto speedup = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return nullptr;
}();

class Solution {
  public:
	vector<int> numsSameConsecDiff(int n, int k) {
		vector<int> ans = {1, 2, 3, 4, 5, 6, 7, 8, 9};
		for (int place = 2; place <= n; place++) {
			vector<int> tempAns;
			for (const auto &ele : ans) {
				int last = ele % 10;
				if (last + k < 10) {
					tempAns.push_back(ele * 10 + last + k);
				}
				if (last - k >= 0) {
					tempAns.push_back(ele * 10 + last - k);
				}
			}
			ans = tempAns;
		}
		set<int> finalAns(ans.begin(), ans.end());
		return vector<int>(finalAns.begin(), finalAns.end());
	}
};