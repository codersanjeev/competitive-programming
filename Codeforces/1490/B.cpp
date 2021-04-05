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
    int n, x = 0, y = 0, z = 0, ans = 0;
    read(n);
    vector<int> arr(n);
    readContainer(arr);
    for (auto &ele : arr) {
        ele %= 3;
        if (ele == 0) {
            x++;
        } else if (ele == 1) {
            y++;
        } else {
            z++;
        }
    }
    n /= 3;

    while (1) {
        if (x == n && y == n && z == n) {
            break;
        }
        if (x > n) {
            x--;
            y++;
            ans++;
        } else if (x < n) {
            x++;
            z--;
            ans++;
        }
        if (y > n) {
            y--;
            z++;
            ans++;
        } else if (y < n) {
            y++;
            x--;
            ans++;
        }
        if (z > n) {
            z--;
            x++;
            ans++;
        } else if (z < n) {
            z++;
            y--;
            ans++;
        }
    }
    write(ans, "\n");
}

signed main() {
    int tc = 1;
    read(tc);
    for (int curr = 1; curr <= tc; curr++) {
        solve(curr);
    }
    return 0;
}