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

const int M = 1e3 + 1;
int dp[M][M];

int solveUtil(vector<int> &t, int idx, int T, int N) {
    if (idx == N) {
        return 0;
    }
    if (T >= (2 * N)) {
        return 5e5;
    }
    if (dp[idx][T] != -1) {
        return dp[idx][T];
    }
    int x = solveUtil(t, idx + 1, T + 1, N) + abs(T - t[idx]);
    int y = solveUtil(t, idx, T + 1, N);
    return dp[idx][T] = min(x, y);
}

void solve(int tc) {
    int N;
    read(N);
    vector<int> t(N);
    readContainer(t);
    sort(t.begin(), t.end());
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            dp[i][j] = -1;
        }
    }
    write(solveUtil(t, 0, 1, N), "\n");
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