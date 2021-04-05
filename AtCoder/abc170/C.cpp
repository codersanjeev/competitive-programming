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
	int x, n, ele;
	cin >> x >> n;
	unordered_map<int, int> mp;
	while(n--) {
		cin >> ele;
		mp[ele]++;
	}
	for(int d = 0; d <= x; d++) {
		for(auto s : {-1, +1}) {
			int a = x + (s * d);
			if(mp[a] == 0) {
				cout << a;
				return;
			}
		}
	}
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
