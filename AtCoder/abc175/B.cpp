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
	int n;
	cin >> n;
	vector<int> arr(n);
	for(auto &ele : arr)
		cin >> ele;
	int ans = 0;
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			for(int k = j + 1; k < n; k++) {
				vector<int> temp = {arr[i], arr[j], arr[k]};
				sort(temp.begin(), temp.end());
				if(arr[i] != arr[j] && arr[j] != arr[k] && arr[i] != arr[k] && temp[0] + temp[1] > temp[2]) {
					ans++;
				} 
			}
		}
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
