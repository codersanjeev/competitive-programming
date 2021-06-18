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

int f(int p, int a) {
    int res = p;
    res = (res * (modpow(p, a) - 1 + mod) % mod) % mod;
    res = (res * modpow(p - 1, mod - 2)) % mod;
    return res;
}

void solve(int tc) {
    int n;
    read(n);
    vector<int> p(n), a(n);
    for (int i = 0; i < n; i++) {
        read(p[i]);
    }
    for (int i = 0; i < n; i++) {
        read(a[i]);
    }
    int ans = 1;
    for (int i = 0; i < n; i++) {
        ans = (ans * f(p[i], a[i])) % mod;
    }
    write(ans, "\n");
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int tc = 1;
    read(tc);
    for (int curr = 1; curr <= tc; curr++) solve(curr);
    return 0;
}