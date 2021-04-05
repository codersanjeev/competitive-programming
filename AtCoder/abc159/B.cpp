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

bool checkPalindrome(string s) {
	int n = s.size();
	int i = 0, j = n - 1;
	while(i < j) {
		if(s[i] != s[j])
			return false;
		i++;
		j--;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin >>s;
	if(!checkPalindrome(s)) {
		cout <<"No\n";
		return 0;
	}
	int n = s.size();
	int l = (n - 1) / 2;
	int e = (n + 1) / 2;
	string a = s.substr(0, l);
	string b = s.substr(e, l);
	if(checkPalindrome(a) && checkPalindrome(b)) {
		cout <<"Yes\n";
	}
	else {
		cout <<"No\n";
	}
	return 0;
}
