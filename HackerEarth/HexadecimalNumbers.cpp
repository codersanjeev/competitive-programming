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

int hexOf(int n) {
	int ans = 0;
	while(n > 0) {
		ans += (n % 16);
		n /= 16;
	}
	return ans;
}

bool check(int x) {
	return __gcd(x, hexOf(x)) > 1;
}

void solve() {
	int L, R, ans = 0;
	cin >> L >> R;
	for(int x = L; x <= R; x++) {
		if(check(x)) ans++;
	}
	cout << ans << "\n";
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int tc = 1;
	cin >> tc;
	while(tc--) {
	    solve();
	}
	return 0;
}
