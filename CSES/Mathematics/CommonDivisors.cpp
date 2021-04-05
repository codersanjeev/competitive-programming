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
	int n, ele;
	cin >> n;
	const int N = 1e6;
	unordered_map<int, int> freq;
	for(int i = 0; i < n; i++) { 
		cin >> ele;
		freq[ele]++;
	}
	for(int i = N; i >= 0; i--) {
		int cnt = 0;
		for(int j = i; j <= N; j += i)
			cnt += freq[j];
		if(cnt > 1) {
			cout << i;
			break;
		}
	}
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
