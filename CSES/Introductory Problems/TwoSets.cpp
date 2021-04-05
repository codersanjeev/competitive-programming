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

void solve() {
	int n;
	cin >> n;
	int sum = (n * (n + 1)) / 2;
	if (sum % 2 == 1) {
		cout << "NO";
	}
	else {
		cout << "YES\n";
		vector<int> A, B;
		sum /= 2;
		while (n) {
			if (sum - n >= 0) {
				A.push_back(n);
				sum -= n;
			}
			else {
				B.push_back(n);
			}
			n--;
		}
		cout << A.size() << "\n";
		for (auto ele : A)
			cout << ele << " ";
		cout << "\n";
		cout << B.size() << "\n";
		for (auto ele : B)
			cout << ele << " ";
		cout << "\n";
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
	solve();
	return 0;
}
