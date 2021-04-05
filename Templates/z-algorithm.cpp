#include <bits/stdc++.h>
using namespace std;

/**
 * Given a string S of length N, it returns an array Z, such that
 * Z[i] = K  =>  S[0, i - 1] == S[i, i + K - 1]
 * 
 * Time Complexity: O(|S|)
 */
vector<int> zFunction(const string &s) {
    int n = s.size(), l = 0, r = 0;
    vector<int> z(n, 0);
    for (int i = 1; i < n; i++) {
        if (i <= r) {
            z[i] = min(r - i + 1, z[i - 1]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            ++z[i];
        }
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}