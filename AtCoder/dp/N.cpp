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
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	vector<int> pre(n);
	pre[0] = arr[0];
	for (int i = 1; i < n; i++)
		pre[i] = pre[i - 1] + arr[i];
	auto pref = [&](int i, int j) {
		if (i == 0)
			return pre[j];
		else
			return pre[j] - pre[i - 1];
	};
	// dp[i][j] -> minimum total cost to combine arr[i:j]
	vector<vector<int>> dp(n, vector<int>(n, LLONG_MAX));
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = i; j < n; j++)
		{
			if (i == j)
			{
				dp[i][j] = 0;
			}
			else
			{
				for (int k = i; k < j; k++)
				{
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + pref(i, j));
				}
			}
		}
	}
	cout << dp[0][n - 1];
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}