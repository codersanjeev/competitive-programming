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

#define deb(x) cout << #x << " is " << x << "\n";

using namespace std;
using namespace __gnu_pbds;

const double PI = 2 * acos(0.0);
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, n, p;
	cin >>t;
	for(int i = 1; i <= t; i++) {
		cin >>n >>p;
		vector<int> arr(n);
		for(int j = 0; j < n; j++)
			cin >>arr[j];
		sort(arr.begin(), arr.end());
		if(p == n) {
			int ans = 0;
			for(auto ele : arr) {
				ans += (arr[n-1] - ele);
			}
			cout <<"Case #" <<i <<": " <<ans <<"\n";
			continue;
		}
		int ans = INT_MAX;
		for(int j = 0; j <= n - p; j++) {
			int curr = 0;
			for(int k = j; k < j + p; k++) {
				curr += (arr[j + p - 1] - arr[k]);
			}
			ans = min(ans, curr);
		}
		cout <<"Case #" <<i <<": " <<ans <<"\n";
	}
	return 0;
}
