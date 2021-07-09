#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 1e9 + 7;

/**
 * Returns count of numbers c such that 1 <= c <= k and c % D = 0
 * 
 * @param
 * s: int, upper limit of numbers.
 * D: int, modulo with this should be zero.
 * i: current index of the number where digit is going to be placed.
 * d: modulo of sum of previous digits i.e. [0, i - 1]
 * flag: denotes restriction, if we can place digits [0, 9] or [0, s[i])
 * dp: for caching already computed values.
 */
int solve(const string &s, int D, int i, int d, bool flag, vector<vector<vector<int>>> &dp) {
    if (i == (int)s.size()) {
        return d == 0;
    }
    if (dp[i][d][flag] != -1) {
        return dp[i][d][flag];
    }
    int ub = (flag ? s[i] - '0' : 9);
    int ans = 0;
    for (int dig = 0; dig <= ub; ++dig) {
        ans = (ans + solve(s, D, i + 1, (d + D - dig % D) % D, flag && dig == ub, dp)) % mod;
    }
    return dp[i][d][flag] = ans;
}

signed main() {
    string k;
    int d;
    cin >> k >> d;
    vector<vector<vector<int>>> dp(k.size(), vector<vector<int>>(d, vector<int>(2, -1)));
    cout << (solve(k, d, 0, 0, true, dp) - 1 + mod) % mod;
    return 0;
}