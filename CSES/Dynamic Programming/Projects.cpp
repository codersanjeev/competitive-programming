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

int binarySearch(const vector<tuple<int, int, int>> &jobs, int index) {
    int lo = 0, hi = index - 1, ans = -1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (get<1>(jobs[mid]) < get<0>(jobs[index])) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return ans;
}

void solve(int tc) {
    int n, ai, bi, pi;
    read(n);
    vector<tuple<int, int, int>> jobs;
    for (int i = 0; i < n; ++i) {
        read(ai, bi, pi);
        jobs.push_back(make_tuple(ai, bi, pi));
    }
    sort(jobs.begin(), jobs.end(), [](const tuple<int, int, int> &a, const tuple<int, int, int> &b) {
        return get<1>(a) < get<1>(b);
    });
    vector<int> dp(n, 0);
    dp[0] = get<2>(jobs[0]);
    for (int i = 1; i < n; ++i) {
        int including = get<2>(jobs[i]);
        int index = binarySearch(jobs, i);
        if (index != -1) {
            including += dp[index];
        }
        int excluding = dp[i - 1];
        dp[i] = max(including, excluding);
    }
    write(dp.back());
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    // read(tc);
    for (int curr = 1; curr <= tc; ++curr) {
        solve(curr);
    }
    return 0;
}