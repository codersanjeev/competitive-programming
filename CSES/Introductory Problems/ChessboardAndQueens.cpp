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

vector<bool> col(16, false), diagonalOne(16, false), diagonalTwo(16, false);
vector<vector<bool>> restricted(8, vector<bool>(8, false));
int ans = 0;

void search(int row) {
	if (row == 8) {
		ans++;
		return;
	}
	for (int column = 0; column < 8; column++) {
		if (col[column] || diagonalOne[row + column] || diagonalTwo[row - column + 7] || restricted[row][column]) {
			continue;
		}
		col[column] = true;
		diagonalOne[row + column] = true;
		diagonalTwo[row - column + 7] = true;
		search(row + 1);
		col[column] = false;
		diagonalOne[row + column] = false;
		diagonalTwo[row - column + 7] = false;
	}
}

void solve() {
	char ch;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> ch;
			if (ch == '*') {
				restricted[i][j] = true;
			}
		}
	}
	search(0);
	cout << ans;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	solve();
	return 0;
}
