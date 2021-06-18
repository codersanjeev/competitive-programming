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
    int n, m;
    read(n, m);
    vector<int> p(m), y(m);
    vector<int> a[n + 1];
    for (int i = 0; i < m; i++) {
        read(p[i], y[i]);
        a[p[i]].push_back(y[i]);
    }
    for (int i = 0; i < n; i++) sort(a[i + 1].begin(), a[i + 1].end());
    for (int i = 0; i < m; i++) {
        int ans = p[i] * 1000000 + (lower_bound(a[p[i]].begin(), a[p[i]].end(), y[i]) - a[p[i]].begin()) + 1;
        cout << setfill('0') << setw(12) << ans << endl;
    }
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