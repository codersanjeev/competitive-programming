class Solution {
  public:
	int findMinArrowShots(vector<vector<int>> &points) {
		int n = points.size(), i = 0, ans = 0;
		sort(points.begin(), points.end(), [](const vector<int> &x, const vector<int> &y) {
			return x[1] < y[1];
		});
		while (i < n) {
			ans++;
			int ending = points[i][1];
			while (i < n && points[i][0] <= ending) {
				i++;
			}
		}
		return ans;
	}
};