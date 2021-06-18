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

template <typename... T>
void read(T &...args) {
    ((cin >> args), ...);
}

template <typename... T>
void write(T &&...args) {
    ((cout << args), ...);
}

void solve(int tc) {
    int n, m;
    read(n, m);

    vector<int> a(m);
    for (int i = 0; i < m; i++)
        read(a[i]);

    vector<int> mp({0, 2, 5, 5, 4, 5, 6, 3, 7, 6});
    vector<string> dp(n + 1, "");
    for (int i = n; i > 0; i--) {
        if (i != n && dp[i].length() == 0)
            continue;
        for (auto j : a) {
            if (i - mp[j] >= 0) {
                string s1 = dp[i - mp[j]];
                string s2 = dp[i] + char(j + '0');

                if (s2.length() > s1.length() || (s2.length() == s1.length() && s2 > s1))
                    dp[i - mp[j]] = s2;
            }
        }
    }

    write(dp[0]);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    int tc = 1;
    // read(tc);
    for (int curr = 1; curr <= tc; curr++) solve(curr);
    return 0;
}