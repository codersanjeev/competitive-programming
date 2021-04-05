#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& a, vector<int>& b, int k) {
    int n = a.size(), m = b.size();
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());
    priority_queue<tuple<int, int, int, bool, bool>> pq;
    set<pair<int, int>> visited;
    pq.emplace(a[0] * b[0], 0, 0, true, true);
    visited.emplace(0, 0);
    if (visited.count({n - 1, m - 1}) == 0) {
        pq.emplace(a[n - 1] * b[m - 1], n - 1, m - 1, false, false);
        visited.emplace(n - 1, m - 1);
    }
    if (visited.count({0, m - 1}) == 0) {
        pq.emplace(a[0] * b[m - 1], 0, m - 1, true, false);
        visited.emplace(0, m - 1);
    }
    if (visited.count({n - 1, 0}) == 0) {
        pq.emplace(a[n - 1] * b[0], n - 1, 0, false, true);
        visited.emplace(n - 1, 0);
    }
    while (k--) {
        auto i = get<1>(pq.top()), j = get<2>(pq.top());
        bool f = get<3>(pq.top()), ff = get<4>(pq.top());
        int ii = i + (f ? 1 : -1);
        int jj = j + (ff ? 1 : -1);
        pq.pop();
        if (0 <= ii && ii < n) {
            if (visited.count({ii, j}) == 0) {
                pq.emplace(a[ii] * b[j], ii, j, f, ff);
                visited.emplace(ii, j);
            }
        }
        if (0 <= jj && jj < m) {
            if (visited.count({i, jj}) == 0) {
                pq.emplace(a[i] * b[jj], i, jj, f, ff);
                visited.emplace(i, jj);
            }
        }
    }
    return get<0>(pq.top());
}