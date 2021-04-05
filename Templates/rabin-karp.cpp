#include <bits/stdc++.h>
using namespace std;

/**
 * Given a string S and a pattern T, find all occurences of T in S
 * Returns all starting indices of T in S
 * 
 * For example: S  =  ababab
 *              T  =  ab
 *              Output  =  [1, 3, 5]
 *
 * Time Complexity  =  O(|S| + |T|) 
 */
vector<int> findOccurences(const string &s, const string &t) {
    int n = s.size(), m = t.size(), p = 31, MOD = 1e9 + 7, patternHash = 0;
    vector<int> ppow(n + m, 0), ans;
    ppow[0] = 1;
    for (int i = 1; i < n + m; i++) {
        ppow[i] = (p * ppow[i - 1]) % MOD;
    }
    vector<int> prefixHash(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefixHash[i + 1] = (prefixHash[i] + (s[i] - 'a' + 1) * ppow[i]) % MOD;
    }
    for (int i = 0; i < m; i++) {
        patternHash = (patternHash + (t[i] - 'a' + 1) * ppow[i]) % MOD;
    }
    for (int i = 0; i + m - 1 < n; i++) {
        int currentHash = (prefixHash[i + m] + MOD - prefixHash[i]) % MOD;
        if (currentHash == (patternHash * ppow[i]) % MOD) {
            ans.push_back(i + 1);
        }
    }
    return ans;
}
