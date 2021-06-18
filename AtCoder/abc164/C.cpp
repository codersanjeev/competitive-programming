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
	// int t, n, k;
	// cin >> t;
	// while (t--) {
	// 	cin >> n >> k;
	// 	vector<int> arr(2 * n);
	// 	for (int i = 0; i < n; i++) {
	// 		cin >> arr[i];
	// 		arr[i + n] = arr[i];
	// 	}
	// 	for (int i = 1; i < arr.size(); i++)
	// 		arr[i] += arr[i - 1];
	// 	int ans = LLONG_MIN;
	// 	for (int start = 0; start < n; start++) {
	// 		int curr = 0;
	// 		if (start == 0)
	// 			curr = arr[start + k];
	// 		else
	// 			curr = arr[start + k] - arr[start - 1];
	// 		ans = max(ans, curr);
	// 	}
	// 	cout << ans << "\n";
	// }
	int n;
	string s;
	unordered_set<string> st;
	cin >> n;
	while (n--) {
		cin >> s;
		st.insert(s);
	}
	cout << st.size();
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
	return 0;
}
