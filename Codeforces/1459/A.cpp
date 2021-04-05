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

template <class... Args>
auto create(size_t n, Args &&...args) {
    if constexpr (sizeof...(args) == 1)
        return vector(n, args...);
    else
        return vector(n, create(args...));
}

auto speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

void solve(int tc) {
    int N;
    read(N);
    char ch;
    vector<pair<int, int>> arr(N);
    for (int i = 0; i < N; i++) {
        read(ch);
        arr[i].first = ch - '0';
    }
    for (int i = 0; i < N; i++) {
        read(ch);
        arr[i].second = ch - '0';
    }
    int red = 0, blue = 0;
    for (const auto &ele : arr) {
        if (ele.first > ele.second) {
            red++;
        } else if (ele.first < ele.second) {
            blue++;
        }
    }
    if (red > blue) {
        write("RED\n");
    } else if (red < blue) {
        write("BLUE\n");
    } else {
        write("EQUAL\n");
    }
}

signed main() {
    int tc = 1;
    read(tc);
    for (int curr = 1; curr <= tc; ++curr) {
        solve(curr);
    }
    return 0;
}