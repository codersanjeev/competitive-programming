const int N = 46;
vector<int> dp(N, -1);

auto speedup = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i < N; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return nullptr;
}();

class Solution {
  public:
	int climbStairs(int n) {
		return dp[n];
	}
};