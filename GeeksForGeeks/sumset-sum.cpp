/* I want to be the very best like no one ever was
https://practice.geeksforgeeks.org/problems/subset-sum-problem/0/
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int isSubsetSum(int set[], int n, int sum) {
	bool dp[n+1][sum+1];
	for (int i=0; i<=n; i++) dp[i][0]=true;
	for (int i=1; i<=sum; i++) dp[0][i]=false;

	for (int i=1; i<=n; i++) {
		for (int j=1; j<=sum; j++) {
			int temp = j-set[i-1];
			if (temp>=0)  {
				dp[i][j] = dp[i-1][j] || dp[i-1][j-set[i-1]];
			}
			else {
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	return dp[n][sum];
}

int main() {
	int t; cin>>t;
	while (t--) {
		int n; cin>>n;
		int set[n];
		for (int i=0; i<n; i++) cin>>set[i];
		int sum; cin>>sum;
		cout << isSubsetSum(set, n, sum) << endl;
	}
}