#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>>& intervals) {
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());
    int last_size = intervals[n - 1][1] - intervals[n - 1][0] + 1;
    vector<int> min_size_on_right(n, last_size);
    for (int i = n - 2; i >= 0; i--) {
        int size = intervals[i][1] - intervals[i][0] + 1;
        min_size_on_right[i] = min(size, min_size_on_right[i + 1]);
    }
    int res = INT_MAX;
    for (int i = 0; i < n; i++) {
        int size = intervals[i][1] - intervals[i][0] + 1;
        int j_start = intervals[i][1] + 1;
        int j = lower_bound(intervals.begin(), intervals.end(), vector<int>{j_start, 0}) - intervals.begin();
        if (j != n) res = min(res, size + min_size_on_right[j]);
    }
    return res == INT_MAX ? 0 : res;
}