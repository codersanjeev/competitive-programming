#include<bits/stdc++.h>

int Solution::solve(const vector<int> &A) {
	int n = A.size();
	int sum = accumulate(A.begin(), A.end(), 0);
	vector<vector<pair<int, int>>> dp((sum / 2) + 1, vector<pair<int, int>>(n + 1, {0, 0}));
	for (int i = 1; i <= sum / 2; i++) {
		for (int j = 1; j <= n; j++) {
			if (A[j - 1] > i) {
				dp[i][j] = dp[i][j - 1];
			} else {
				pair<int, int> incl{dp[i - A[j - 1]][j - 1].first + A[j - 1], 1 + dp[i - A[j - 1]][j - 1].second};
				pair<int, int> excl{dp[i][j - 1].first, dp[i][j - 1].second};
				auto comp = [](const pair<int, int> &a, const pair<int, int> &b) {
					if (a.first == b.first) {
						return a.second < b.second;
					}
					return a.first > b.first;
				};
				dp[i][j] = min(incl, excl, comp);
			}
		}
	}
	return dp[sum / 2][n].second;
}
