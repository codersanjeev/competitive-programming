/*
MAXIMUM SUM INCREASING SUBSEQUENCE BY DYNAMIC PROGRAMMING
https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence/0/
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int lis(int arr[], int pos) {
	int dp[pos+1];
	// max sum of subsequence of first ele is itself
	dp[0] = arr[0];

	for (int i=1; i<=pos-1; i++) {
		int maxx = 0;
		for (int j=0; j<i; j++) {
			if (arr[i] > arr[j]) {
				if (dp[j] > maxx) maxx = dp[j];
			}
		}
		dp[i] = arr[i] + maxx;
	}

	// find the max element in dp
	int max_ = INT_MIN;
	for (int i=0; i<pos; i++) max_ = max(max_, dp[i]);
	return max_;
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