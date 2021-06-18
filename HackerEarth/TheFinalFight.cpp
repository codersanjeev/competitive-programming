#pragma GCC optimize("O3")
#pragma GCC target("sse4")

#include <bits/stdc++.h>

using namespace std;

#define deb(x) cout << #x << " is " << x << "\n"
#define int long long
#define mod 1000000009
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

int modpow(int x, int y) {
    x %= mod;
    int ans = 1;
    while (y > 0) {
        if (y & 1) {
            ans = (ans * x) % mod;
        }
        x = (x * x) % mod;
        y >>= 1;
    }
    return ans;
}

void solve(int tc) {
    int n;
    read(n);
    int res = 1, temp = 1;
    for (int i = 2; i <= n; i++) {
        res = (res * (n + i)) % mod;
        temp = (temp * i) % mod;
    }
    res = (res * modpow(temp, mod - 2)) % mod;
    write(res, "\n");
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int tc = 1;
    // read(tc);
    for (int curr = 1; curr <= tc; curr++) solve(curr);
    return 0;
}