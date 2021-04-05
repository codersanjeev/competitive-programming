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
const long long INF = 1e18L + 5;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long N, W;
	cin >>N >>W;
	vector<pair<long long, long long>> arr(N);
	long long totalValue = 0LL;
	for(long long i = 0LL; i < N; i++){
		cin >>arr[i].first >>arr[i].second;
		totalValue += arr[i].second;
	}
	// dp[i] = minimum total weight with value exactly i
	vector<long long> dp(totalValue + 1LL, INF);
	dp[0] = 0LL;
	for(long long i = 0LL; i < N; i++) {
		for(long long v = totalValue - arr[i].second; v >= 0LL; v--) {
			dp[v + arr[i].second] = min(dp[v + arr[i].second], dp[v] + arr[i].first);
		}
	}
	long long ans = 0LL;
	for(long long i = 0LL; i <= totalValue; i++) {
		if(dp[i] <= W) {
			ans = max(ans, i);
		}
	}
	cout <<ans;
	return 0;
}
