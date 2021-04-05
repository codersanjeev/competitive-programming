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
	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	vector<int> dp(k + 1, 0);
	// dp[i] -> number of ways such that we used i candies so far
	dp[0] = 1;
	for (int child = 0; child < n; child++)
	{
		int upto = arr[child];
		vector<int> temp(k + 1);
		for (int used = k; used >= 0; used--)
		{
			int L = used + 1;
			int R = used + min(upto, k - used);
			if (L <= R)
			{
				temp[L] = (temp[L] + dp[used]) % mod;
				if (R + 1 <= k)
				{
					temp[R + 1] = ((temp[R + 1] - dp[used]) + mod) % mod;
				}
			}
		}
		int curr = 0;
		for (int i = 0; i <= k; i++)
		{
			curr = (curr + temp[i]) % mod;
			dp[i] = (dp[i] + curr) % mod;
		}
	}
	cout << dp[k];
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}