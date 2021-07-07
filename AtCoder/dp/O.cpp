#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int solve(const vector<vector<int>> &arr, vector<vector<int>> &dp, int i, int mask, int n) {
    if (i == n) return mask == 0;
    if (dp[i][mask] != -1) return dp[i][mask];
    int ans = 0;
    for (int w = 0; w < n; ++w) {
        bool ok = ((1 << w) & mask) != 0;
        if (ok && arr[i][w] == 1) {
            ans = (ans + solve(arr, dp, i + 1, mask ^ (1 << w), n)) % mod;
        }
    }
    return dp[i][mask] = ans;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));
    for (auto &row : arr) {
        for (auto &ele : row) cin >> ele;
    }
    vector<vector<int>> dp(n, vector<int>(1 << n, -1));
    int ans = solve(arr, dp, 0, (1 << n) - 1, n);
    cout << ans;
    return 0;
}