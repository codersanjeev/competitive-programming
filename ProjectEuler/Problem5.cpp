#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		int ans = 1LL;
		for (int i = 1; i <= n; i++) {
			ans = (ans * i) / __gcd(ans, i);
		}
		cout << ans << "\n";
	}
	return 0;
}
