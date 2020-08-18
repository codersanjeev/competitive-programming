/*
https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps/0/
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int minJumps(vector<int> &dp, int arr[], int pos, int n) {
	// if result is already computed, return it
	if (dp[pos] != -1) return dp[pos];
	// base conditions
	if (pos>=n) return INT_MAX;
	if (pos==n-1) return 0;

	int maxjump=arr[pos];
	int minvalue = INT_MAX;
	for (int i=1; i<=maxjump; i++) {
		minvalue = min(minvalue, minJumps(dp, arr, pos+i, n));
	}

	// if none of the option takes us ahead, then minvalue will be INT_MAX. So don't increase it
	if (minvalue==INT_MAX)
		dp[pos] = INT_MAX;
	else
		dp[pos] = minvalue + 1;
	return dp[pos];
}

int main() {
	int t; cin>>t;
	while (t--) {
		int n; cin>>n;
		int arr[n];
		for (int i=0; i<n; i++) cin>>arr[i];
		vector<int> dp(n+1, -1);
		int ans = minJumps(dp, arr, 0, n);
		// if no jumps possible
		if (ans == INT_MAX) ans = -1;
		cout << ans << endl;
	}
}