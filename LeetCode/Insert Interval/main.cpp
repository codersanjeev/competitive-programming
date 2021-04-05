class Solution {
  public:
	vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval) {
		intervals.push_back(newInterval);
		return merge(intervals);
	}

  private:
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
};