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
	int d, n, k, ans;
	cin >> n >> k >> d;
	
	if (n < 0) n = -n;
	
	if (n / d < k) {
		int rest = k - n / d;
		if (rest % 2 == 0) ans = n % d;
		else ans = d - n % d;
	} else {
		ans = n - d * k;
	}
	cout << ans << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int tc = 1;
	// cin >> tc;
	while(tc--) {
	    solve();
	}
	return 0;
}
