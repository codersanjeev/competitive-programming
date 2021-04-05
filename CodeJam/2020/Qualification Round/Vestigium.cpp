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

#define mod 1000000007

const double PI = 2 * acos(0.0);
const long long INF = 1e18L + 5;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
	int t, n;
	cin >>t;
	int tc = 1;
	while(t--) {
		cin >>n;
		vector<vector<int>> arr(n, vector<int>(n));
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				cin >>arr[i][j];
			}
		}
		int s = 0;
		for(int i = 0; i < n; i++) {
			s += arr[i][i];
		}
		int r = 0, c = 0;
		for(int i = 0; i < n; i++) {
			unordered_map<int, int> mp;
			for(int j = 0; j < n; j++) {
				mp[arr[i][j]]++;
			}
			if(mp.size() != n) {
				r++;
			}
		}
		for(int j = 0; j < n; j++) {
			unordered_map<int, int> mp;
			for(int i = 0; i < n; i++) {
				mp[arr[i][j]]++;
			}
			if(mp.size() != n) {
				c++;
			}
		}
		cout <<"Case #" <<tc <<": " <<s <<" " <<r <<" " <<c <<"\n";
		tc++;
	}
	return 0;
}
