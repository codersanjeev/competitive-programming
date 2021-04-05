class Solution {
   public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        for (int i = 0; i < n - 1; i++) {
            int ending = intervals[i][1];
            int start = intervals[i + 1][0];
            if (start < ending) {
                return false;
            }
        }
        return true;
    }
};