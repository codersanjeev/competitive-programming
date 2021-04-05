#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("trapv")
#pragma GCC target("sse4")

#include <bits/stdc++.h>
using namespace std;

#define deb(x) cout << #x << " is " << x << "\n"
#define int long long
#define mod 1000000007
#define PI acos(-1)

void solve() {
	int n, ai, bi, pi;
	cin >> n;
	vector<vector<int>> arr(n, vector<int>(3));
	for(int i = 0; i < n; i++) {
		cin >> ai >> bi >> pi;
		arr[i][1] = ai;
		arr[i][0] = bi;
		arr[i][2] = pi;
	}
	sort(arr.begin(), arr.end());
	set<pair<int, int>> dp;
	dp.insert({0, 0});
	int ans = 0;
	for(int i = 0; i < n; i++) {
		auto it = dp.lower_bound({arr[i][1], 0});
		--it;
		ans = max(ans, (*it).second + arr[i][2]);
		dp.insert({arr[i][0], ans});
	}
	cout << ans;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
	int tc = 1;
	// cin >> tc;
	while(tc--) {
	    solve();
	}
	return 0;
}
