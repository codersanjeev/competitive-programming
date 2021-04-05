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
	int t, n;
	cin >>t;
	int tc = 1;
	while(t--) {
		cin >>n;
		vector<vector<int>> arr(n, vector<int>(3));
		for(int i = 0; i < n; i++) {
			cin >>arr[i][0] >>arr[i][1];
			arr[i][2] = i;
		}
		sort(arr.begin(), arr.end());
		vector<int> l(2, INT_MAX);
		vector<string> players = {"C", "J"};
		vector<string> ans(n);
		bool answerFound = false;
		for(int i = n - 1; i >= 0; i--) {
			bool flag = false;
			int p1 = 0, p2 = 1;
			if(l[p1] > l[p2]) {
				swap(p1, p2);
			}
			if(arr[i][1] <= l[p1]) {
				flag = true;
				ans[arr[i][2]] = players[p1];
				l[p1] = arr[i][0];
			}
			if(!flag && arr[i][1] <= l[p2]) {
				flag = true;
				ans[arr[i][2]] = players[p2];
				l[p2] = arr[i][0];
			}
			if(!flag) {
				cout <<"Case #" <<tc <<": IMPOSSIBLE\n";
				tc++;
				answerFound = true;
				break;
			}
		}
		if(!answerFound) {
			cout <<"Case #" <<tc <<": ";
			for(auto ele : ans)
				cout <<ele;
			cout <<"\n";
			tc++;
		}
	}
	return 0;
}
