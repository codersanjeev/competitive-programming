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
void read(T &... args) {
    ((cin >> args), ...);
}

template <typename... T>
void write(T &&... args) {
    ((cout << args), ...);
}

template <typename T>
void readContainer(T &t) {
    for (auto &e : t) read(e);
}

template <typename T>
void writeContainer(T &t) {
    for (const auto &e : t) write(e, " ");
    write("\n");
}

int nCr(int n, int r) {
    // n! / r! * (n - r)!
    // n * (n - 1) * ... * (n - r + 1) / r!
    int res = 1;
    r = min(r, n - r);
    for (int i = n; i > (n - r); i--) {
        res *= i;
    }
    for (int i = 2; i <= r; i++) {
        res /= i;
    }
    return res;
}

void solve(int tc) {
    int n, k;
    read(n, k);
    int ans = 0;
    if (k >= 2) {
        ans += nCr(n, 2);
    }
    if (k >= 3) {
        ans += 2 * nCr(n, 3);
    }
    if (k >= 4) {
        ans += 9 * nCr(n, 4);
    }
    write(1 + ans);
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