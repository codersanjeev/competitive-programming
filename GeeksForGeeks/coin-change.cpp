/* I want to be the very best like no one ever was
https://practice.geeksforgeeks.org/problems/coin-change/0/
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int change(int coins[], int m, int n) {
	int dp[m+1][n+1];
	for (int i=0; i<=m; i++) dp[i][0]=1;
	for (int i=1; i<=n; i++) dp[0][i]=0;

	for (int i=1; i<=m; i++) {
		for (int j=1; j<=n; j++) {
			int temp = j-coins[i-1];
			if (temp>=0) temp = dp[i][temp];
			else temp=0;
			dp[i][j] = dp[i-1][j] + temp;
		}
	}
	return dp[m][n];
}

int main() {
	int t; cin>>t;
	while (t--) {
		int m; cin>>m;
		int coins[m];
		for (int i=0; i<m; i++) cin>>coins[i];
		int n; cin>>n;
		cout << change(coins, m, n) << endl;
	}
}