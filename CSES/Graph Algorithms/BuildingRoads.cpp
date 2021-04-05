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

int findRoot(vector<int> &arr, int u) {
    while (u != arr[u]) {
        arr[u] = arr[arr[u]];
        u = arr[u];
    }
    return u;
}

void unionTree(vector<int> &arr, int x, int y) {
    int u = findRoot(arr, x);
    int v = findRoot(arr, y);
    if (u != v) {
        arr[u] = v;
    }
}

void solve(int tc) {
    int n, m, u, v;
    read(n, m);
    vector<int> parent(n);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
    while (m--) {
        read(u, v);
        u--;
        v--;
        unionTree(parent, u, v);
    }
    set<int> st;
    for (int i = 0; i < n; i++) {
        u = findRoot(parent, i);
        st.insert(u);
    }
    write(st.size() - 1, "\n");
    vector<int> ans(st.begin(), st.end());
    for (int i = 0; i < ans.size() - 1; i++) {
        write(ans[i] + 1, "\n", ans[i + 1] + 1, "\n");
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