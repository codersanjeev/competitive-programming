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
#define int long long
#define mod 1000000007

const double PI = 2 * acos(0.0);
const long long INF = 1e18L + 5;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	double n, m;
	cin >>n >>m;
	vector<double> arr((int)n);
	for(int i = 0; i < n; i++) {
		cin >>arr[i];
	}
	sort(arr.begin(), arr.end());
	reverse(arr.begin(), arr.end());
	double required = accumulate(arr.begin(), arr.end(), 0.0) / (4.0 * m);
	if(arr[m-1] < required) {
		cout <<"No";
	} 
	else {
		cout <<"Yes";
	}
	return 0;
}
