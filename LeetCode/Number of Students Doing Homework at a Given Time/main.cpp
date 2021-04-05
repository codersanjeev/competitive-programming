class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        vector<int> ans(1002, 0);
        int n = startTime.size();
        for (int i = 0; i < n; i++) {
            ans[startTime[i]]++;
            ans[endTime[i] + 1]--;
        }
        for (int i = 1; i < 1002; i++) ans[i] += ans[i - 1];
        return ans[queryTime];
    }
};