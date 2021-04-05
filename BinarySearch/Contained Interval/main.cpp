bool check(int x, int y, int a, int b) {
	return a >= x && b <= y;
}

bool solve(vector<vector<int>> &intervals) {
	sort(intervals.begin(), intervals.end());
	int n = intervals.size();
	for (int i = 1; i < n; i++) {
		if (check(intervals[i - 1][0], intervals[i - 1][1], intervals[i][0], intervals[i][1]) || check(intervals[i][0], intervals[i][1], intervals[i - 1][0], intervals[i - 1][1])) {
			return true;
		}
	}
	return false;
}