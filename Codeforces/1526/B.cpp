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

vector<int> arr = {11, 111, 1111, 11111, 111111, 1111111, 11111111, 111111111};
map<int, int> cache;

bool check(int n) {
    if (n < 0) return false;
    for (const auto &ele : arr) {
        if (n % ele == 0) return true;
    }
    int res = cache[n];
    if (res == -1) {
        return false;
    } else if (res == 1) {
        return true;
    }
    for (const auto &ele : arr) {
        if (check(n - ele)) {
            cache[n] = 1;
            return true;
        }
    }
    cache[n] = -1;
    return false;
}

void solve(int tc) {
    int n;
    read(n);
    write((check(n) ? "YES\n" : "NO\n"));
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    reverse(arr.begin(), arr.end());
    int tc = 1;
    read(tc);
    for (int curr = 1; curr <= tc; ++curr) {
        solve(curr);
    }
    return 0;
}