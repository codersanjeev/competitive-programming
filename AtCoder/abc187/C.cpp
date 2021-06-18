#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pll pair<int,int>
#define vpll vector <pll>
#define pb push_back
#define f(i,a,n) for(int i=a;i<n;i++)
#define PI 3.14159265358979323846
const int N = 1e18 + 5;

int32_t main() {
	int n;
	cin >> n;
	set<string> s1;
	set<string> s2;
	f(i, 0, n) {
		string t;
		cin >> t;
		if (t[0] == '!') {
			t = t.substr(1);
			s1.insert(t);
		} else { s2.insert(t); }
	}
	for (auto i : s1) {
		if (s2.count(i)) {
			cout << i;
			return 0;
		}
	}
	cout << "satisfiable";
	return 0;
}