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
	long long n;
	cin >>n;
	vector<long long> ans(3, 0);
	for(long long i = 0; i < n; i++) {
		vector<long long> curr(3);
		vector<long long> dp(3, 0);
		for(long long i = 0; i < 3; i++)
			cin >>curr[i];
		for(long long i = 0; i < 3; i++) {
			for(long long j = 0; j < 3; j++) {
				if(i != j) {
					dp[j] = max(dp[j], ans[i] + curr[j]);
				}
			}
		}
		ans = dp;
	}
	cout <<max({ans[0], ans[1], ans[2]});
	return 0;
}
