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

vector<int> bit;

void updateTree(int idx, int ele, int n) {
    while (idx <= n) {
        bit[idx] += ele;
        idx += (idx & -idx);
    }
}

int getSum(int idx) {
    int ans = 0;
    while (idx > 0) {
        ans += bit[idx];
        idx -= (idx & -idx);
    }
    return ans;
}

void solve(int tc) {
    int n, m, c, u, v, k;
    char ch;
    read(n, m, c);
    // arr = [c, c, c, c, c, ...]
    bit.resize(n + 1, 0);
    while (m--) {
        read(ch);
        if (ch == 'S') {
            read(u, v, k);
            // for i in [u, v] arr[i] += k ???
            // arr[u] += k and arr[v + 1] -= k
            updateTree(u, k, n);
            updateTree(v + 1, -k, n);
        } else {
            read(u);
            // print(arr[u]) ???
            write(getSum(u) + c, "\n");
        }
    }
}

signed main() {
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