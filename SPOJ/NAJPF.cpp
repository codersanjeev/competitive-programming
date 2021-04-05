#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("fast-math")

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define deb(x) cout << #x << " is " << x << "\n"
#define int long long
#define MOD 1000000007LL
#define PI acos(-1)

template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

template <typename T>
using max_heap = priority_queue<T>;

template <class T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

auto speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

void solve(int tc) {
    vector<int> ans;
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    int p = 31;
    vector<int> ppow(n + m, 0);
    ppow[0] = 1;
    for (int i = 1; i < n + m; i++) {
        ppow[i] = (p * ppow[i - 1]) % MOD;
    }
    vector<int> prefixHash(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefixHash[i + 1] = (prefixHash[i] + (s[i] - 'a' + 1) * ppow[i]) % MOD;
    }
    int patternHash = 0;
    for (int i = 0; i < m; i++) {
        patternHash = (patternHash + (t[i] - 'a' + 1) * ppow[i]) % MOD;
    }
    for (int i = 0; i + m - 1 < n; i++) {
        int currentHash = (prefixHash[i + m] + MOD - prefixHash[i]) % MOD;
        if (currentHash == (patternHash * ppow[i]) % MOD) {
            ans.push_back(i + 1);
        }
    }
    if (ans.empty()) {
        cout << "Not Found\n";
    } else {
        cout << ans.size() << "\n";
        for (const auto &ele : ans) {
            cout << ele << " ";
        }
        cout << "\n";
    }
}

signed main() {
    int tc = 1;
    cin >> tc;
    for (int curr = 1; curr <= tc; ++curr) {
        solve(curr);
    }
    return 0;
}