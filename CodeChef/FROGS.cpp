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

auto speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

void solve(int tc) {
    int N;
    read(N);
    vector<int> W(N), L(N);
    readContainer(W);
    readContainer(L);
    if (N == 2) {
        if (W[0] < W[1]) {
            write("0\n");
            return;
        }
        if (L[0] == 1) {
            write("2\n");
        } else {
            write("1\n");
        }
        return;
    }
    vector<pair<int, int>> indexes(N);
    for (int i = 0; i < N; i++) {
        int index = i + 1;
        int value = W[i];
        indexes[value - 1] = {index, index};
    }
    int ans = 0;
    for (int i = 1; i < N; i++) {
        while (indexes[i].first <= indexes[i - 1].first) {
            indexes[i].first += L[indexes[i].second - 1];
            ans++;
        }
        if (i - 2 >= 0) {
            while (indexes[i].first <= indexes[i - 2].first) {
                indexes[i].first += L[indexes[i].second - 1];
                ans++;
            }
        }
        if (i - 3 >= 0) {
            while (indexes[i].first <= indexes[i - 3].first) {
                indexes[i].first += L[indexes[i].second - 1];
                ans++;
            }
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