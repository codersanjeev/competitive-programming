/****************************************************
*   Template for coding contests                    *
*   Author    :    Sanjeev Sharma                   *
*   Email     :    thedevelopersanjeev@gmail.com    *
*****************************************************/
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("fast-math")
#pragma GCC target("sse4")

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define deb(x) cout << #x << " is " << x << "\n"
#define int long long
#define mod 1000000007

const double PI = 2 * acos(0.0);
const long long INF = 1e18L + 5;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <class... Args>
auto create(size_t n, Args &&...args) {
    if constexpr (sizeof...(args) == 1)
        return vector(n, args...);
    else
        return vector(n, create(args...));
}

template <typename... T>
void read(T &...args) {
    ((cin >> args), ...);
}

template <typename... T>
void write(T &&...args) {
    ((cout << args), ...);
}

struct segtree {
    int size;
    vector<pair<int, int>> tree;

    void init(int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.resize(2 * size);
    }

    pair<int, int> merge(pair<int, int> a, pair<int, int> b) {
        if (a.first < b.first)
            return a;
        if (a.first > b.first)
            return b;
        return {a.first, a.second + b.second};
    }

    void build(vector<int> &arr, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < arr.size()) {
                tree[x] = {arr[lx], 1};
            }
            return;
        }
        int mx = lx + (rx - lx) / 2;
        build(arr, 2 * x + 1, lx, mx);
        build(arr, 2 * x + 2, mx, rx);
        tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void build(vector<int> &arr) {
        build(arr, 0, 0, size);
    }

    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            tree[x] = {v, 1};
            return;
        }
        int mx = lx + (rx - lx) / 2;
        if (i < mx) {
            set(i, v, 2 * x + 1, lx, mx);
        } else {
            set(i, v, 2 * x + 2, mx, rx);
        }
        tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
    }

    pair<int, int> sum(int l, int r, int x, int lx, int rx) {
        if (lx >= r || rx <= l)
            return {INT_MAX, 0};
        if (lx >= l && rx <= r)
            return tree[x];
        int mx = lx + (rx - lx) / 2;
        return merge(sum(l, r, 2 * x + 1, lx, mx), sum(l, r, 2 * x + 2, mx, rx));
    }

    pair<int, int> sum(int l, int r) {
        return sum(l, r, 0, 0, size);
    }

    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }
};

void solve() {
    int n, m, t, a, b;
    read(n, m);
    segtree st;
    st.init(n);
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        read(arr[i]);
    st.build(arr);
    while (m--) {
        read(t, a, b);
        if (t == 1) {
            st.set(a, b);
        } else {
            auto ans = st.sum(a, b);
            write(ans.first, " ", ans.second, "\n");
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solve();
    return 0;
}
