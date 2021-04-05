class Solution {
  public:
	int totalFruit(vector<int> &tree) {
		pair<int, int> type = { -1, -1};
		int curr = 0, ans = 0, prev = 0;
		for (const auto &ele : tree) {
			if (ele == type.first || ele == type.second) {
				curr++;
			} else {
				curr = prev + 1;
			}
			if (ele == type.second) {
				prev++;
			} else {
				prev = 1;
			}
			if (ele != type.second) {
				type.first = type.second;
				type.second = ele;
			}
			ans = max(ans, curr);
		}
		return ans;
	}
};