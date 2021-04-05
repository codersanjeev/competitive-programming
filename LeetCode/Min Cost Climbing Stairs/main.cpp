auto speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
    	vector<int> dp(1001, -1);
    	return min(solve(0, cost.size(), cost, dp), solve(1, cost.size(), cost, dp));
    }
private: 
	int solve(int curr, int target, const vector<int> &cost, vector<int> &dp) {
		if (curr >= target) {
			return 0;
		}
		if (dp[curr] != -1) return dp[curr];
		return dp[curr] = (cost[curr] + min(solve(curr + 1, target, cost, dp), solve(curr + 2, target, cost, dp)));
	}
};