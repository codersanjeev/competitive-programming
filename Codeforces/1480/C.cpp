#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")

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

// auto speedup = []() {
// 	ios::sync_with_stdio(false);
// 	cin.tie(nullptr);
// 	cout.tie(nullptr);
// 	return nullptr;
// }();

int n;

int query(int index) {
    write("? ", index + 1, "\n");
    int ele;
    read(ele);
    return ele;
}

int check(int c) {
    int ele = query(c);
    int left = query(c - 1 < 0 ? c : c - 1);
    int right = query(c + 1 >= n ? c : c + 1);
    if (right < ele) {
        return 1;
    } else if (left < ele) {
        return -1;
    } else {
        return 0;
    }
}

int solve(int l, int r) {
    while (l <= r) {
        int m = l + (r - l) / 2;
        int res = check(m);
        if (res == 0) {
            return m + 1;
        } else if (res == 1) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return -1;
}

void solve(int tc) {
    int N;
    read(N);
    n = N;
    write("! ", solve(0, N - 1));
}

signed main() {
    int tc = 1;
    // read(tc);
    for (int curr = 1; curr <= tc; curr++) {
        solve(curr);
    }
    return 0;
}