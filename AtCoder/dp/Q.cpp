#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n;
    cin >> n;
    vector<pair<int, int>> flower(n);
    for (int i = 0; i < n; ++i) cin >> flower[i].first;
    for (int i = 0; i < n; ++i) cin >> flower[i].second;
    vector<int> dp(n, 0);
    map<int, int> mp;
    dp[0] = flower[0].second;
    mp[flower[0].first] = flower[0].second;
    for (int i = 1; i < n; ++i) {
        dp[i] = flower[i].second;
        auto it = mp.lower_bound(flower[i].first + 1);
        if (it != mp.begin()) {
            --it;
            dp[i] += it->second;
        }
        mp[flower[i].first] = dp[i];
        it = mp.upper_bound(flower[i].first);
        while (it != mp.end() && it->second <= dp[i]) {
            auto tempIterator = it;
            ++tempIterator;
            mp.erase(it);
            it = tempIterator;
        }
    }
    cout << *max_element(dp.begin(), dp.end());
    return 0;
}