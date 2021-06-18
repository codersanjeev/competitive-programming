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

// int Solution::solve(vector<int> &arr) {

// 	const long long mod = (long long) 1e9 + 7;
// 	long long n = (long long) arr.size();


// }

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, ele;
	cin >> n;
	vector<int> ans(n, 0);
	for (int i = 0; i < n - 1; i++) {
		cin >> ele;
		ans[ele - 1]++;
	}
	for (auto x : ans)
		cout << x << "\n";
	return 0;
}
