#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n, k;
    cin >> n >> k;
    vector<int> id(n);
    for (auto &ele : id) cin >> ele;
    vector<int> ans(n, k / n);
    k %= n;
    unordered_map<int, int> idMap;
    for (int i = 0; i < n; ++i) {
        idMap[id[i]] = i;
    }
    sort(begin(id), end(id));
    for (const auto &ele : id) {
        if (k == 0) break;
        ++ans[idMap[ele]];
        --k;
    }
    for (const auto &ele : ans) {
        cout << ele << "\n";
    }
    return 0;
}