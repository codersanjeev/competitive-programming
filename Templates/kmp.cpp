#include <bits/stdc++.h>
using namespace std;

/**
* Prefix Function: length of longest proper prefix which is also a suffix.
* 
*		PI[i]  =  max{k : S[0...k - 1] == S[i - (k - 1)...i]}
* 
*/

/// Brute Force Implementation
//  Time Complexity  :  O(N ^ 3) where N = |S|
vector<int> prefix_function(const string &s) {
    int n = s.size();
    vector<int> pi(n);
    for (int i = 0; i < n; i++) {
        for (int k = 0; k <= i; k++) {
            if (s.substr(0, k) == s.substr(i - k + 1, k)) {
                pi[i] = k;
            }
        }
    }
    return pi;
}

/// Optimal Approach
//  Time Complexity  :  O(N) where N = |S|
vector<int> prefix_function(const string &s) {
    int n = s.size();
    vector<int> pi(n, 0);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        pi[i] = j;
    }
    return n;
}
