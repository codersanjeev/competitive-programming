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

void solve(int tc) {
    int N;
    read(N);
    if (N <= 1e3 - 1) {
        write(0);
    } else if (N <= 1e6 - 1) {
        int ans = N - 1e3 + 1;
        write(ans);
    } else if (N <= 1e9 - 1) {
        int ans = 1e6 - 1e3;
        ans += (N - 1e6 + 1) * 2;
        write(ans);
    } else if (N <= 1e12 - 1) {
        int ans = 1e6 - 1e3;
        ans += (1e9 - 1e6) * 2;
        ans += (N - 1e9 + 1) * 3;
        write(ans);
    } else if (N <= 1e15 - 1) {
        int ans = 1e6 - 1e3;
        ans += (1e9 - 1e6) * 2;
        ans += (1e12 - 1e9) * 3;
        ans += (N - 1e12 + 1) * 4;
        write(ans);
    } else {
        int ans = 1e6 - 1e3;
        ans += (1e9 - 1e6) * 2;
        ans += (1e12 - 1e9) * 3;
        ans += (1e15 - 1e12) * 4;
        write(ans + 5);
    }
}

signed main() {
    int tc = 1;
    // read(tc);
    for (int curr = 1; curr <= tc; ++curr) {
        solve(curr);
    }
    return 0;
}