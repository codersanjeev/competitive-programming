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
	long long N, W;
	cin >>N >>W;
	vector<pair<long long, long long>> arr(N);
	for(long long i = 0; i < N; i++)
		cin >>arr[i].first >>arr[i].second;
	// dp[i] = maximum possible weight by conidering weight exactly i
	vector<long long> dp(W + 1);
	for(long long i = 0; i < N; i++) {
		long long weight = arr[i].first;
		long long value = arr[i].second;
		for(long long w = W - weight; w >= 0; w--) {
			dp[w + weight] = max(dp[w + weight], dp[w] + value);
		}
	}
	cout <<*max_element(dp.begin(), dp.end());
	return 0;
}
