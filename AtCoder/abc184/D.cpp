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

const int n = 1e2 + 1;
long double dp[n][n][n];
bool visited[n][n][n];

long double solveUtil(int a, int b, int c) {
    if (a == 100 || b == 100 || c == 100) {
        return 0;
    }
    if (visited[a][b][c] == true) {
        return dp[a][b][c];
    }
    visited[a][b][c] = true;
    int s = a + b + c;
    long double x = (a * 1.0) / s;
    long double y = (b * 1.0) / s;
    long double z = (c * 1.0) / s;
    long double ans = (x * solveUtil(a + 1, b, c)) + (y * solveUtil(a, b + 1, c)) + (z * solveUtil(a, b, c + 1));
    return dp[a][b][c] = 1.0 + ans;
}

void solve(int tc) {
    int a, b, c;
    memset(visited, false, sizeof(visited));
    read(a, b, c);
    cout << fixed << setprecision(16) << solveUtil(a, b, c);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    int tc = 1;
    // read(tc);
    for (int curr = 1; curr <= tc; curr++) solve(curr);
    return 0;
}