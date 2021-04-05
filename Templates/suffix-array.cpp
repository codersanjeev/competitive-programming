#include <bits/stdc++.h>
using namespace std;

/**
 * Counting Sort  =  O(N)
 */
void countingSort(vector<int> &p, vector<int> &c) {
    int n = p.size();
    vector<int> cnt(n);
    for (const auto &ele : c) {
        cnt[ele]++;
    }
    vector<int> pNew(n), pos(n);
    pos[0] = 0;
    for (int i = 1; i < n; i++) {
        pos[i] = pos[i - 1] + cnt[i - 1];
    }
    for (const auto &ele : p) {
        pNew[pos[c[ele]]] = ele;
        pos[c[ele]]++;
    }
    p = pNew;
}

/**
 * Build Suffix Array from the given String
 * Suffix Array: indexes of suffix of given string in lexicographic sorted order.
 * Example: string = "ababba"
 * suffix array  =  [6, 5, 0, 2, 4, 1, 3]
 *
 * Time Complexity: O(N * log(N)) where N = |S|
 */
vector<int> suffixArray(const string &S) {
    string s = S + "$";
    int n = s.size();
    vector<int> p(n), c(n);
    {
        vector<pair<char, int>> a(n);
        for (int i = 0; i < n; i++) a[i] = {s[i], i};
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++) p[i] = a[i].second;
        c[p[0]] = 0;
        for (int i = 1; i < n; i++) {
            if (a[i].first == a[i - 1].first) {
                c[p[i]] = c[p[i - 1]];
            } else {
                c[p[i]] = c[p[i - 1]] + 1;
            }
        }
    }
    int k = 0;
    while ((1 << k) < n) {
        for (int i = 0; i < n; i++) {
            p[i] = (p[i] - (1 << k) + n) % n;
        }
        countingSort(p, c);
        vector<int> cNew(n);
        cNew[p[0]] = 0;
        for (int i = 1; i < n; i++) {
            pair<int, int> prev = make_pair(c[p[i - 1]], c[(p[i - 1] + (1 << k)) % n]);
            pair<int, int> now = make_pair(c[p[i]], c[(p[i] + (1 << k)) % n]);
            if (prev == now) {
                cNew[p[i]] = cNew[p[i - 1]];
            } else {
                cNew[p[i]] = cNew[p[i - 1]] + 1;
            }
        }
        c = cNew;
        k++;
    }
    return p;
}
