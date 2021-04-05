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

bool possible(const vector<pair<long double, long double>> &arr, long double x) {
    int N = arr.size();
    vector<pair<long double, long double>> sg(N);
    for (int i = 0; i < N; i++) {
        sg[i].first = arr[i].first + (x * arr[i].second);
        sg[i].second = arr[i].first - (x * arr[i].second);
    }
    // sort(sg.begin(), sg.end());
    pair<long double, long double> temp = *min_element(sg.begin(), sg.end());
    int ans = 1;
    for (int i = 1; i < N; i++) {
        if (sg[i].second <= temp.first) {
            ans++;
        }
    }
    return ans == N;
}

void solve(int tc) {
    int N;
    read(N);
    vector<pair<long double, long double>> coordinates(N);
    for (int i = 0; i < N; i++) {
        read(coordinates[i].first, coordinates[i].second);
    }
    long double lo = 0, hi = 2e9;
    int ops = 60;
    while (ops--) {
        long double mid = lo + (hi - lo) / 2;
        if (possible(coordinates, mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    cout << fixed << setprecision(16) << lo;
}

signed main() {
    int tc = 1;
    // read(tc);
    for (int curr = 1; curr <= tc; ++curr) {
        solve(curr);
    }
    return 0;
}