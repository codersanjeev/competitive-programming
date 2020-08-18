/*
https://practice.geeksforgeeks.org/problems/trapping-rain-water/0/
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int capacity(int arr[], int n) {
	int max_ = INT_MIN;
	int left[n], right[n];
	for (int i=0; i<n; i++) {
		max_ = max(max_, arr[i]);
		left[i] = max_;
	}
	max_ = INT_MIN;
	for (int i=n-1; i>=0; i--) {
		max_ = max(max_, arr[i]);
		right[i] = max_;
	}
	// compute sum
	int sum=0;
	for (int i=0; i<n; i++) {
		sum += min(left[i], right[i]) - arr[i];
	}
	return sum;
}

int main() {
	int t; cin>>t;
	while (t--) {
		int n; cin>>n;
		int arr[n];
		for (int i=0; i<n; i++) cin>>arr[i];
		cout << capacity(arr, n) << endl;
	}
}