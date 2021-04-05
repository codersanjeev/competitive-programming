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

bool good(const vector<int> &arr, int rate) {
    const int N = arr.size();
    int curr = 0;
    for (int i = 0; i < N; i++) {
        curr += rate;
        if (curr >= 50000000000) return true;
        if (curr < arr[i]) {
            return false;
        }
    }
    return true;
}

void solve(int tc) {
    int N, mx = INT_MIN;
    read(N);
    int Li, Ri, Zi;
    vector<pair<int, int>> arr(N);
    for (int i = 0; i < N; i++) {
        read(Li, Ri, Zi);
        mx = max(mx, Ri);
        // arr[Ri - 1] += Zi;
        arr[i] = {Ri - 1, Zi};
    }
    vector<int> pre(mx, 0);
    for (int i = 0; i < N; i++) {
        pre[arr[i].first] += arr[i].second;
    }
    for (int i = 1; i < mx; i++) {
        pre[i] += pre[i - 1];
    }
    int lo = 0, hi = 50000000000, ans = -1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (good(pre, mid)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    write(ans, "\n");
}

signed main() {
    int tc = 1;
    read(tc);
    for (int curr = 1; curr <= tc; ++curr) {
        solve(curr);
    }
    return 0;
}