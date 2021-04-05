class Solution {
  public:
	int eraseOverlapIntervals(vector<vector<int>> &intervals) {
		int ans = 0, end = INT_MIN;
		sort(intervals.begin(), intervals.end(), [](const vector<int> &x, const vector<int> &y) {
			return x[1] < y[1];
		});
		for (const auto &interval : intervals) {
			if (interval[0] >= end) {
				end = interval[1];
			} else {
				ans++;
			}
		}
		return ans;
	}
};