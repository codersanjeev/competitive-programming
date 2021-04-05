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
	int n;
	string s;
	cin >>n; 
	unordered_map<string, int> mp;
	while(n--) {
		cin >>s;
		mp[s]++;
	}
	int mx = INT_MIN;
	for(auto ele : mp) {
		mx = max(mx, ele.second);
	}
	vector<string> arr;
	for(auto ele : mp) {
		if(ele.second == mx) {
			arr.push_back(ele.first);
		}
	}
	sort(arr.begin(), arr.end());
	for(auto ele : arr) {
		cout <<ele <<"\n";
	}
	return 0;
}
