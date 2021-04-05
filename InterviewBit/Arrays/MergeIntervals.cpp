/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
	if (newInterval.start > newInterval.end) {
		Interval interval = Interval(newInterval.end, newInterval.start);
		intervals.push_back(interval);
	} else {
		intervals.push_back(newInterval);
	}
	sort(intervals.begin(), intervals.end(), [](const Interval & A, const Interval & B) -> bool {
		return A.start < B.start;
	});
	int n = intervals.size();
	vector<Interval> ans;
	ans.push_back(intervals[0]);
	for (int i = 1; i < n; i++) {
		// if overlapping, update ending point of my answer
		if (intervals[i].start <= ans[ans.size() - 1].end) {
			ans[ans.size() - 1].end = max(intervals[i].end, ans[ans.size() - 1].end);
		}
		// else, add new interval to answer
		else {
			ans.push_back(intervals[i]);
		}
	}
	return ans;
}
