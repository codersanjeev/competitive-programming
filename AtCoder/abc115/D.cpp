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

int p[55], nlen[55];

int solve(int n, int x) {
    if (x <= n) return 0;
    if (x >= nlen[n] - 1) return p[n];
    if (x == nlen[n] / 2 + 1)
        return (p[n] / 2 + 1);
    else if (x < nlen[n] / 2 + 1)
        return solve(n - 1, x - 1);
    else
        return p[n] / 2 + 1 + solve(n - 1, x - nlen[n] / 2 - 1);
}

void solve(int tc) {
    int n, x;
    read(n, x);
    write(solve(n, x));
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    int tc = 1;
    for (int i = 0; i <= 50; ++i) {
        p[i] = pow(2, i + 1) - 1;
        nlen[i] = pow(2, i - 1) * 8 - 3;
    }
    // read(tc);
    for (int curr = 1; curr <= tc; curr++) solve(curr);
    return 0;
}