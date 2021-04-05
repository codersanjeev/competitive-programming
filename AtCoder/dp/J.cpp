/****************************************************
*   Template for coding contests                    *
*   Author    :    Sanjeev Sharma                   *
*   Email     :    thedevelopersanjeev@gmail.com    *
*****************************************************/
#pragma GCC optimize ("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("fast-math")
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

double dp[301][301][301];

double findAnswer(int one, int two, int three, int n) {
	if((one < 0 || two < 0 || three < 0) || (one == 0 && two == 0 && three == 0))
		return 0;
	if(dp[one][two][three] > 0)
		return dp[one][two][three];
	return dp[one][two][three] = (n + one * findAnswer(one - 1, two, three, n) + two * findAnswer(one + 1, two - 1, three, n) + three * findAnswer(one, two + 1, three - 1, n)) / (one + two + three);
}

void solve() {
	int n, ele, ones = 0, twos = 0, threes = 0;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> ele;
		if(ele == 1)
			ones++;
		else if(ele == 2)
			twos++;
		else 
			threes++;
	}
	memset(dp, -1.0, sizeof(dp));
	cout << fixed << setprecision(14) << findAnswer(ones, twos, threes, n);
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
	return 0;
}
