#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main() {
	long long int t; cin>>t;
	while (t--) {
		long long int n, k, min_step=INT_MAX, ans=-1;
		cin>>n>>k;

		for (long long int i=0; i<n; i++) {
			long long int p; cin>>p;
			if (p<k && k%p == 0) {
				long long int step = k/p;
				if (step < min_step) {
					min_step = step;
					ans = p;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}