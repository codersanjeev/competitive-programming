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
    cout.tie(nullptr);
    return nullptr;
}();

void solve(int tc) {
    int n;
    read(n);
    // n * (n - 1) / 2 integers
    // 1 2, 1 3, 1 4, ..., 1 n, 2 3, 2 4, ..., n - 1, n
    // 1  -> x wins
    // -1 -> y wins
    // 0  -> draw
    if (n % 2 == 0) {
        vector<vector<int>> ans(n, vector<int>(n));
        for (int i = 0; i < n; i += 2) {
            ans[i][i + 1] = ans[i + 1][i] = 0;
            for (int j = i + 2; j < n; j += 2) {
                ans[i][j] = ans[i + 1][j + 1] = 1;
                ans[i][j + 1] = ans[i + 1][j] = -1;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                write(ans[i][j], " ");
            }
        }
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if ((i + j) % 2 == 0) {
                    write(1, " ");
                } else {
                    write(-1, " ");
                }
            }
        }
    }
    write("\n");
}

signed main() {
    int tc = 1;
    read(tc);
    for (int curr = 1; curr <= tc; curr++) {
        solve(curr);
    }
    return 0;
}