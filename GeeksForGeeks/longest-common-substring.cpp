/* I want to be the very best like no one ever was */

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int lcs(string s1, string s2, int m, int n) {
	int dp[m+1][n+1];
	int result=0;
	memset(dp, -1, sizeof(dp));
	for (int i=0; i<=m; i++) {
		for (int j=0; j<=n; j++) {
			if (i==0 || j==0) dp[i][j] = 0;
			else if (s1[i-1]==s2[j-1]) {
				dp[i][j] = 1 + dp[i-1][j-1];
				if (dp[i][j] > result) result = dp[i][j];
			}
			else dp[i][j] = 0;
		}
	}
	return result;
}

int main()
 {
	int t; cin>>t;
	while (t--) {
		string s1; string s2;
		cin>>s1>>s2;
		cout << lcs(s1, s2, s1.length(), s2.length()) << endl;
	}
	return 0;
}