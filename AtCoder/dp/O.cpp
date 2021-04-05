#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("trapv")
#pragma GCC target("sse4")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define deb(x) cout << #x << " is " << x << "\n"
#define int long long
#define mod 1000000007LL
#define PI acosl(-1)

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve()
{
	int n;
	cin >> n;
	vector<vector<int>> arr(n, vector<int>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}
	vector<int> dp(1LL << n);
	dp[0] = 1;
	for (int mask = 0; mask < (1LL << n) - 1; mask++)
	{
		int a = __builtin_popcount(mask);
		for (int b = 0; b < n; b++)
		{
			if (arr[a][b] == 1 && (mask & (1LL << b)) == 0)
			{
				int newmask = mask ^ (1LL << b);
				dp[newmask] = (dp[newmask] + dp[mask]) % mod;
			}
		}
	}
	cout << dp[(1LL << n) - 1];
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}