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
    int n;
    read(n);
    vector<int> S(n), C(n);
    readContainer(S);
    readContainer(C);
    const int INF = 1e17;
    vector<vector<int>> dp(n + 1, vector<int>(3, INF));
    int ans = INF;
    for (int i = 0; i < n; i++) {
        dp[i][0] = C[i];
        for (int j = 1; j < 3; j++) {
            dp[i][j] = INF;
            for (int k = 0; k < i; k++) {
                if (S[k] < S[i])
                    dp[i][j] = min(dp[i][j], dp[k][j - 1] + C[i]);
            }
        }
        ans = min(ans, dp[i][2]);
    }
    if (ans == INF) ans = -1;
    write(ans);
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