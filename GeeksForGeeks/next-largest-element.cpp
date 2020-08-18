#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
	int t; cin>>t;
	while (t--) {
		int n; cin>>n;
		ll arr[n], ans[n];
		for (int i=0; i<n; i++) cin>>arr[i];
		stack<ll> s;
		for (int i=n-1; i>=0; i--) {
			while( !s.empty() && arr[i]>=s.top())
				s.pop();
			if (s.empty()) ans[i] = -1;
			else ans[i] = s.top();
			s.push(arr[i]);
		}

		for (int i=0; i<n; i++) cout << ans[i] << " ";
		cout << endl;
	}
}