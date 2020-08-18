/* I want to be the very best like no one ever was */
/*
https://practice.geeksforgeeks.org/problems/edit-distance/0/
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int lcs(string s1, string s2, int m, int n) {
    int dp[m+1][n+1];
    for (int i=0; i<=m; i++) {
        for (int j=0; j<=n; j++) {
            if (i==0 || j==0)
                dp[i][j] = max(i,j);
            else if (s1[i-1]==s2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else {
                int a1 = dp[i-1][j] + 1;
                int a2 = dp[i][j-1] + 1;
                int a3 = dp[i-1][j-1] + 1;
                dp[i][j] = min(min(a1,a2),a3);
            }
        }
    }
    return dp[m][n];
}

int main() {
    int t; cin>>t;
    while (t--) {
        int m,n; cin>>m>>n;
        string s1, s2;
        cin>>s1; cin>>s2;
        cout << lcs(s1, s2, m, n) << endl;
    }
}