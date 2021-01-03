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
	string s, t;
	cin >> s >> t;
	int ans = INT_MAX;
	int n = s.size(), m = t.size();
	for(int i = 0; i < n - m + 1; i++) {
		string curr = s.substr(i, m);
		int cnt = 0;
		for(int j = 0; j < m; j++) {
			// deb(curr[j]);
			// deb(t[j]);
			if(curr[j] != t[j]) {
				cnt++;
			}
			
			// deb(cnt);
		}
		ans = min(ans, cnt);
	}
	cout << ans;
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