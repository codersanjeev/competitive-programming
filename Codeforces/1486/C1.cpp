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

// auto speedup = []() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     return nullptr;
// }();

map<pair<int, int>, int> _cache;

int query(int l, int r) {
    pair<int, int> curr = make_pair(l, r);
    if (_cache[curr] != 0) {
        return _cache[curr];
    }
    write("? ", l, " ", r, "\n");
    int ans;
    read(ans);
    return _cache[curr] = ans;
}

void solve(int tc) {
    int n, ans = 1;
    read(n);
    int mid = query(1, n);
    if (1 < mid && mid == query(1, mid)) {
        int L = 1, R = mid;
        while (L + 1 != R) {
            int M = (L + R) / 2;
            if (mid == query(M, n)) {
                L = M;
            } else {
                R = M;
            }
        }
        ans = L;
    } else {
        int L = mid, R = n;
        while (L + 1 != R) {
            int M = (L + R) / 2;
            if (query(mid, M) == mid) {
                R = M;
            } else {
                L = M;
            }
        }
        ans = R;
    }
    write("! ", ans, "\n");
}

signed main() {
    int tc = 1;
    // read(tc);
    for (int curr = 1; curr <= tc; curr++) {
        solve(curr);
    }
    return 0;
}