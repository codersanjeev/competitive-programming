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
    int N, Q, X1, X2, Y1, Y2;
    read(N, Q);
    vector<vector<char>> arr(N, vector<char>(N));
    vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            read(arr[i][j]);
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];

            if (arr[i - 1][j - 1] == '*') {
                dp[i][j]++;
            }
        }
    }

    while (Q--) {
        read(X1, Y1, X2, Y2);
        int ans = dp[X2][Y2];
        ans -= dp[X1 - 1][Y2];
        ans -= dp[X2][Y1 - 1];
        ans += dp[X1 - 1][Y1 - 1];
        write(ans, "\n");
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //  freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
    // #endif
    int tc = 1;
    // read(tc);

    for (int curr = 1; curr <= tc; curr++) solve(curr);

    return 0;
}