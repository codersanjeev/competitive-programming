const int MAX = 501;
int dp[MAX][MAX];

int maxcoinutil(vector<int> &coins, int turn, int i, int j) {
	if (i > j) {
		return dp[i][j] = 0;
	}
	if (dp[i][j] != -1) {
		return dp[i][j];
	}
	if (turn == 0) {
		return dp[i][j] = max(coins[i] + maxcoinutil(coins, turn ^ 1, i + 1, j), coins[j] + maxcoinutil(coins, turn ^ 1, i, j - 1));
	} else {
		return dp[i][j] = min(maxcoinutil(coins, turn ^ 1, i, j - 1), maxcoinutil(coins, turn ^ 1, i + 1, j));
	}
}

int Solution::maxcoin(vector<int> &coins) {
	memset(dp, -1, sizeof(dp));
	return maxcoinutil(coins, 0, 0, coins.size() - 1);
}
