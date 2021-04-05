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
	int n, m, s, c;
	cin >> n >> m;
	vector<int> num(n, -1);
	while (m--) {
		cin >> s >> c;
		if (num[--s] != -1 && num[s] != c || n > 1 && !s && !c) {
			cout << -1 << '\n';
			return 0;
		}
		num[s] = c;
	}
	for (int i = 0; i < n; ++i)
		cout << (num[i] == -1 ? (n > 1 && !i) : num[i]);
	cout << '\n';
	return 0;
}
