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

int dfs(int curr, int a, int b, int c, int A, int B, int C, vector<int> &L) {
    if (curr == L.size()) {
        if (min({a, b, c}) > 0) {
            return abs(a - A) + abs(b - B) + abs(c - C) - 30;
        } else {
            return INT_MAX;
        }
    }
    return min({dfs(curr + 1, a, b, c, A, B, C, L),
                dfs(curr + 1, a + L[curr], b, c, A, B, C, L) + 10,
                dfs(curr + 1, a, b + L[curr], c, A, B, C, L) + 10,
                dfs(curr + 1, a, b, c + L[curr], A, B, C, L) + 10});
}

void solve(int tc) {
    int n, a, b, c;
    read(n, a, b, c);
    vector<int> l(n);
    for (int i = 0; i < n; i++) {
        read(l[i]);
    }
    cout << dfs(0, 0, 0, 0, a, b, c, l);
}

int32_t main() {
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