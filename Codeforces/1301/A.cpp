#pragma GCC optimize("O3")
#pragma GCC target("sse4")

#include <bits/stdc++.h>

using namespace std;

#define deb(x) cout << #x << " is " << x << "\n"
#define int long long
#define mod 1000000007
#define PI acos(-1)

template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

template <typename T>
using max_heap = priority_queue<T>;

void solve(int tc) {
    string a, b, c;
    int n;
    cin >> a >> b >> c;
    n = a.size();
    bool ok = true;
    for (int i = 0; i < n; i++) {
        if (a[i] == c[i] || b[i] == c[i]) {
            continue;
        } else {
            ok = false;
            break;
        }
    }
    cout << (ok ? "YES\n" : "NO\n");
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int tc = 1;
    cin >> tc;
    for (int curr = 1; curr <= tc; curr++) solve(curr);
    return 0;
}