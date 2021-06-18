class Solution {
   public:
    int maximumWealth(vector<vector<int>> &accounts) {
        int ans = INT_MIN;
        for (const auto &row : accounts) {
            int curr = 0;
            for (const auto &ele : row) {
                curr += ele;
            }
            if (curr > ans) ans = curr;
        }
        return ans;
    }
};