#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 1e9 + 7;

signed main() {
    int H, W;
    cin >> H >> W;
    vector<vector<char>> grid(H, vector<char>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> grid[i][j];
        }
    }
    vector<vector<int>> dp(H, vector<int>(W, 0));
    dp[H - 1][W - 1] = 1;
    for (int i = H - 1; i >= 0; --i) {
        for (int j = W - 1; j >= 0; --j) {
            if (grid[i][j] == '.') {
                if (i + 1 < H) dp[i][j] = (dp[i][j] + dp[i + 1][j]) % mod;
                if (j + 1 < W) dp[i][j] = (dp[i][j] + dp[i][j + 1]) % mod;
            }
        }
    }
    cout << dp[0][0];
    return 0;
}