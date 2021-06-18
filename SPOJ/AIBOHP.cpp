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

template <typename T>
void readContainer(T &t) {
    for (auto &e : t) read(e);
}

template <typename T>
void writeContainer(T &t) {
    for (const auto &e : t) write(e, " ");
    write("\n");
}

const int M = 6101;
int dp[M][M];

int f(string &s, int n, int lo, int hi) {
    if (hi <= lo) {
        return 0;
    }
    if (dp[lo][hi] != -1) {
        return dp[lo][hi];
    }
    return (dp[lo][hi] = (s[lo] != s[hi] ? 1 + min(f(s, n, lo + 1, hi), f(s, n, lo, hi - 1)) : f(s, n, lo + 1, hi - 1)));
}

void solve(int tc) {
    string s;
    read(s);
    int n = s.size();
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            dp[i][j] = -1;
        }
    }
    write(f(s, n, 0, n - 1), "\n");
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