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

pair<int, int> dfs(vector<int> adj[], int a, int b)
{
	int white = 1, black = 0;
	for (const auto &u : adj[a])
	{
		if (u != b)
		{
			auto curr = dfs(adj, u, a);
			int temp = white;
			white = (white * curr.second) % mod;
			black = ((temp * curr.first) % mod + (black * (curr.first + curr.second)) % mod) % mod;
		}
	}
	return {white, white + black};
}

void solve()
{
	int n, x, y;
	cin >> n;
	vector<int> adj[n];
	for (int i = 0; i < n - 1; i++)
	{
		cin >> x >> y;
		x--;
		y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	auto p = dfs(adj, 0, 0);
	cout << (p.first + p.second) % mod;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}