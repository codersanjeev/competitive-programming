class Solution {
   public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        int n = calories.size(), ans = 0;
        for (int i = 1; i < n; i++) {
            calories[i] += calories[i - 1];
        }
        for (int i = 0; i < n - k + 1; i++) {
            int curr = calories[i + k - 1];
            if (i > 0) {
                curr -= calories[i - 1];
            }
            if (curr < lower) {
                ans--;
            } else if (curr > upper) {
                ans++;
            }
        }
        return ans;
    }
};