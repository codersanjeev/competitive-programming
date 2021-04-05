class Solution {
  public:

	vector<vector<int>> merge(vector<vector<int>> &intervals) {
		sort(intervals.begin(), intervals.end());
		vector<vector<int>> ans;
		if (intervals.empty()) {
			return ans;
		}
		ans.push_back(intervals[0]);
		for (int i = 1; i < intervals.size(); i++) {
			if (ans.back()[1] >= intervals[i][0]) {
				ans.back()[1] = max(ans.back()[1], intervals[i][1]);
			} else {
				ans.push_back(intervals[i]);
			}
		}
		return ans;
	}

	vector<int> partitionLabels(string s) {
		int n = s.size();
		vector<vector<int>> intervals;
		for (char ch = 'a'; ch <= 'z'; ch++) {
			int x = -1, y = -1;
			for (int i = 0; i < n; i++) {
				if (s[i] == ch) {
					x = i;
					break;
				}
			}
			for (int i = n - 1; i >= 0; i--) {
				if (s[i] == ch) {
					y = i;
					break;
				}
			}
			if (x != -1) {
				intervals.push_back({x, y});
			}
		}
		intervals = merge(intervals);
		vector<int> ans;
		for (const auto &ele : intervals) {
			ans.push_back(ele[1] - ele[0] + 1);
		}
		return ans;
	}
};