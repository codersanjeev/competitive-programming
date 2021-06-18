#include<bits/stdc++.h>
using namespace std;

int main() {
	int H, W, K;
	const int MOD = 1e9 + 7;
	cin >> H >> W >> K;
	vector<vector<int>> dp(H + 1, vector<int>(W));
	dp[0][0] = 1;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			for (int k = 0; k < (1 << (W - 1)); k++) {
				bool ok = true;
				for (int l = 0; l < W - 2; l++) {
					if (((k >> l) & 1) && ((k >> (l + 1)) & 1)) {
						ok = false;
					}
				}
				if (ok) {
					if (j >= 1 && ((k >> (j - 1)) & 1)) {
						dp[i + 1][j - 1] += dp[i][j];
						dp[i + 1][j - 1] %= MOD;
					} else if (j <= W - 2 && ((k >> j) & 1)) {
						dp[i + 1][j + 1] += dp[i][j];
						dp[i + 1][j + 1] %= MOD;
					} else {
						dp[i + 1][j] += dp[i][j];
						dp[i + 1][j] %= MOD;
					}
				}
			}
		}
	}
	cout << dp[H][K - 1];
	return 0;
}