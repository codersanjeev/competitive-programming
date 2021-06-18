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
    int h, w;
    read(h, w);
    vector<vector<int>> arr(h, vector<int>(w));
    vector<vector<int>> dp(h, vector<int>(w, 0));
    for (auto &row : arr) {
        readContainer(row);
    }
    for (int j = 0; j < w; j++) {
        dp[0][j] = arr[0][j];
    }
    for (int i = 0; i < h - 1; i++) {
        for (int j = 0; j < w; j++) {
            if (j > 0) {
                dp[i + 1][j - 1] = max(dp[i + 1][j - 1], dp[i][j] + arr[i + 1][j - 1]);
            }
            if (j < w - 1) {
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + arr[i + 1][j + 1]);
            }
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + arr[i + 1][j]);
        }
    }
    write(*max_element(dp[h - 1].begin(), dp[h - 1].end()), "\n");
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