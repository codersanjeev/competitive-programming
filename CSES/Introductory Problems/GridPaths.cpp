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

string s;
vector<int> dx = {0, 0, 1, -1};
vector<int> dy = {1, -1, 0, 0};
vector<vector<bool>> visited(7, vector<bool>(7, false));

int solve(int i, int j, int idx) {
    if (i == 6 && j == 6) return 1;
    if (i < 0 || j < 0 || i >= 7 || j >= 7 || visited[i][j] || idx >= 48) return 0;
    visited[i][j] = true;
    int ans = 0;
    if (s[idx] == 'L') {
        ans += solve(i, j - 1, idx + 1);
    } else if (s[idx] == 'R') {
        ans += solve(i, j + 1, idx + 1);
    } else if (s[idx] == 'U') {
        ans += solve(i - 1, j, idx + 1);
    } else if (s[idx] == 'D') {
        ans += solve(i - 1, j, idx + 1);
    } else {
        for (int k = 0; k < 4; ++k) {
            ans += solve(i + dx[k], j + dy[k], idx + 1);
        }
    }
    visited[i][j] = false;
    return ans;
}

void solve(int tc) {
    read(s);
    int ans = solve(0, 0, 0);
    write(ans);
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