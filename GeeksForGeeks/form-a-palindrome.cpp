/*
https://practice.geeksforgeeks.org/problems/form-a-palindrome/0
*/
/*
to form a palindrome out of a string we need to insert the same no. of characters
as the no. of characters req to be deleted
to form its longest palindromic subsequence
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int lcs(string s1, string s2, int m, int n, int store[][100]) {
	if (m==0 || n==0) return 0;
	// if result exists already
	if (store[m-1][n-1] != -1) return store[m-1][n-1];

	// if last characters are equal
	if (s1[m-1] == s2[n-1]) {
		int temp = lcs(s1, s2, m-1, n-1, store) + 1;
		store[m-1][n-1] = temp;
		return temp;
	}
	// otherwise
	int lcs1 = lcs(s1, s2, m-1, n, store);
	int lcs2 = lcs(s1, s2, m, n-1, store);
	store[m-1][n-1] = max(lcs1, lcs2);
	return store[m-1][n-1];
}


int main()
 {
	int t; cin>>t;
	while (t--) {
		string s1; cin>>s1;
		string s2 = s1;
		reverse(s2.begin(), s2.end());
		int l = s1.length();
		int store[100][100];
		memset(store, -1, sizeof(store));
		int lcsresult = lcs(s1, s2, l, l, store);

		cout << l-lcsresult << endl;
	}
	return 0;
}