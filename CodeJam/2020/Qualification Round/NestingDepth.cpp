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
	int t;
	string s;
	cin >>t;
	int tc = 1;
	while(t--) {
		cin >>s;
		string ans = "";
		int currentDepth = 0;
		for(auto ch : s) {
			int requiredDepth = ch - '0';
			while(requiredDepth > currentDepth) {
				currentDepth++;
				ans += "(";
			}
			while(requiredDepth < currentDepth) {
				currentDepth--;
				ans += ")";
			}
			ans += ch;
		}
		while(currentDepth > 0) {
			currentDepth--;
			ans += ")";
		}
		cout <<"Case #" <<tc <<": " <<ans <<"\n";
		tc++;
	}
	return 0;
}
