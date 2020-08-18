/*
LONGEST INCREASING SUBSEQUENCE BY DYNAMIC PROGRAMMING
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int lis(int arr[], int pos) {
	vector<int> dp(pos+1, 1);

	for (int i=1; i<=pos-1; i++) {
		for (int j=0; j<i; j++) {
			if (arr[i] > arr[j]) {
				if (dp[j]+1 > dp[i]) dp[i] = dp[j]+1;
			}
		}
	}
	return dp[pos-1];
}

int main() {
	int t; cin>>t;
	while (t--) {
		int n; cin>>n;
		int arr[n];
		for (int i=0; i<n; i++) cin>>arr[i];
		int ans = lis(arr, n);
		cout << ans << endl;
	}
}