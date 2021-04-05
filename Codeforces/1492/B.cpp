#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("fast-math")

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define deb(x) cout << #x << " is " << x << "\n"
#define int long long
#define MOD 1000000007LL
#define PI acos(-1)

template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

template <typename T>
using max_heap = priority_queue<T>;

template <class T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename... T>
void read(T &...args) {
    ((cin >> args), ...);
}

template <typename... T>
void write(T &&...args) {
    ((cout << args), ...);
}

template <typename T>
void readContainer(T &t) {
    for (auto &e : t) {
        read(e);
    }
}

template <typename T>
void writeContainer(T &t) {
    for (const auto &e : t) {
        write(e, " ");
    }
    write("\n");
}

auto speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

void solve(const vector<int> &arr, unordered_map<int, int> &index, const vector<int> &maxValue, int i, int j) {
    if (i > j) {
        return;
    }
    int mx = maxValue[j];
    int k = index[mx];
    // deb(mx);
    // deb(k);
    for (int temp = k; temp <= j; temp++) {
        write(arr[temp], " ");
    }
    solve(arr, index, maxValue, i, k - 1);
}

void solve(int tc) {
    int n;
    read(n);
    vector<int> p(n);
    vector<int> mx(n);
    readContainer(p);
    mx[0] = p[0];
    for (int i = 1; i < n; i++) {
        mx[i] = max(mx[i - 1], p[i]);
    }
    unordered_map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        mp[p[i - 1]] = i - 1;
    }
    solve(p, mp, mx, 0, n - 1);
    write("\n");
}

signed main() {
    int tc = 1;
    read(tc);
    for (int curr = 1; curr <= tc; ++curr) {
        solve(curr);
    }
    return 0;
}