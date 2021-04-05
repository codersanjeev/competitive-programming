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
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long n;
	cin >>n;
	vector<long long> arr(n);
	for(long long i = 0; i < n; i++)
		cin >>arr[i];
	unordered_map<long long, long long> mp;
	for(auto ele : arr)
		mp[ele]++;
	long long ans = 0LL;	
	for(auto x : mp) {
		if(x.second >= 2) {
			ans += ((x.second * (x.second - 1)) / 2);
		}
	}
	for(auto ele : arr) {
		long long temp = ans;
		if(mp[ele] >= 2) {
			temp -= (mp[ele] * (mp[ele] - 1) / 2);
		}
		if(mp[ele] - 1 >= 2) {
			if(mp[ele] - 1 == 2) {
				temp += 1;
			} 
			else {
				temp += ((mp[ele] - 1) * (mp[ele] - 2) / 2);
			}
		}
		cout <<temp <<"\n";
	}
	return 0;
}
