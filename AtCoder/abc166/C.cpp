/****************************************************
*   Template for coding contests                    *
*   Author    :    Sanjeev Sharma                   *
*   Email     :    thedevelopersanjeev@gmail.com    *
*****************************************************/
#pragma GCC optimize ("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize("no-stack-protector,fast-math")
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
	int n, m, ai, bi;
	cin >> n >> m;
	vector<int> h(n);
	for (int i = 0; i < n; i++)
		cin >> h[i];
	vector<int> adj[n];
	while (m--) {
		cin >> ai >> bi;
		ai--;
		bi--;
		adj[ai].push_back(bi);
		adj[bi].push_back(ai);
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		bool flag = true;
		for (auto ele : adj[i]) {
			if (h[ele] >= h[i])
				flag = false;
		}
		if (flag)
			ans++;
	}
	cout << ans;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
	return 0;
}
