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
    string a, b;
    read(a, b);
    int n = a.size(), m = b.size();
    vector<vector<int>> dpOne(n + 1, vector<int>(m + 1));
    vector<vector<int>> dpTwo(m + 1, vector<int>(n + 1));
    for (int i = 0; i <= n; i++) {
        dpOne[i][0] = i;
    }
    for (int j = 0; j <= m; j++) {
        dpOne[0][j] = j;
    }
    for (int i = 0; i <= m; i++) {
        dpTwo[i][0] = i;
    }
    for (int j = 0; j <= n; j++) {
        dpTwo[0][j] = j;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) {
                dpOne[i][j] = dpOne[i - 1][j - 1];
            } else {
                dpOne[i][j] = 1 + min({dpOne[i - 1][j], dpOne[i][j - 1], dpOne[i - 1][j - 1]});
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (b[i - 1] == a[j - 1]) {
                dpTwo[i][j] = dpTwo[i - 1][j - 1];
            } else {
                dpTwo[i][j] = 1 + min({dpTwo[i - 1][j], dpTwo[i][j - 1], dpTwo[i - 1][j - 1]});
            }
        }
    }
    write(min(dpOne[n][m], dpTwo[m][n]), "\n");
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