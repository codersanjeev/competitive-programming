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
	int a, b, c, k;
	cin >> a >> b >> c >> k;
	int lo = 0, hi = 1e5 + 5;
	while(hi - lo > 1) {
		int mid = lo + (hi - lo) / 2;
		int curr = ((a * mid * mid) + (b * mid) + c);
		if(curr >= k){
			hi = mid;
		}
		else{
			lo = mid;
		}
	}
	int curr = ((a * lo * lo) + (b * lo) + c);
	if(curr >= k)
		cout << lo << "\n";
	else
		cout << hi << "\n";
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
