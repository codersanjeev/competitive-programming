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

void solve(int tc) {
    int v1, v2, t, d;
    read(v1, v2, t, d);
    vector<vector<int>> dp(t, vector<int>(1000, LLONG_MIN));
    dp[0][v1] = 0;
    for (int i = 0; i < t - 1; i++) {
        for (int j = 0; j < 1000; j++) {
            for (int k = -d; k <= d; k++) {
                if (j + k >= 0 && j + k < 1000) {
                    dp[i + 1][j + k] = max(dp[i + 1][j + k], dp[i][j] + j);
                }
            }
        }
    }
    write(dp[t - 1][v2] + v2);
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