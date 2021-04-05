/****************************************************
*   Template for coding contests                    *
*   Author    :    Sanjeev Sharma                   *
*   Email     :    thedevelopersanjeev@gmail.com    *
*****************************************************/
#pragma GCC optimize ("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("fast-math")
#pragma GCC target ("sse4")
#pragma comment(linker, "/stack:200000000")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define deb(x) cout << #x << " is " << x << "\n";
#define int long long
#define mod 1000000007

const double PI = 2 * acos(0.0);
const long long INF = 1e18L + 5;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<char>> board(n, vector<char>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
	}
	vector<vector<int>> dp(n, vector<int>(m));
	dp[0][0] = 1;
	for (int j = 1; j < m; j++) {
		if (board[0][j] == '#')
			dp[0][j] = 0;
		else
			dp[0][j] = dp[0][j - 1];
	}
	for (int i = 1; i < n; i++) {
		if (board[i][0] == '#')
			dp[i][0] = 0;
		else
			dp[i][0] = dp[i - 1][0];
	}
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (board[i][j] == '#')
				dp[i][j] = 0;
			else
				dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
		}
	}
	cout << dp[n - 1][m - 1];
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
	return 0;
}
