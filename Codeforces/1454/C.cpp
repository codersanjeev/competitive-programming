#pragma GCC optimize("O3")
#pragma GCC target("sse4")

#include <bits/stdc++.h>

using namespace std;

#define deb(x) cout << #x << " is " << x << "\n"
#define int long long
#define mod 1000000007
#define PI acos(-1)

template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

template <typename T>
using max_heap = priority_queue<T>;

template <typename... T>
void read(T &... args) {
    ((cin >> args), ...);
}

template <typename... T>
void write(T &&... args) {
    ((cout << args), ...);
}

template <typename T>
void readContainer(T &t) {
    for (auto &e : t) read(e);
}

template <typename T>
void writeContainer(T &t) {
    for (const auto &e : t) write(e, " ");
    write("\n");
}

void solve(int tc) {
    int n;
    read(n);
    vector<int> arr(n);
    readContainer(arr);
    unordered_map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        mp[arr[i]].push_back(i);
    }
    int ans = LLONG_MAX;
    for (const auto &ele : mp) {
        int ops = 0;
        vector<int> curr = ele.second;
        int m = curr.size();
        if (curr[0] != 0) ops++;
        for (int i = 1; i < m; i++) {
            if (curr[i] - curr[i - 1] > 1) ops++;
        }
        if (curr[m - 1] != n - 1) ops++;
        ans = min(ans, ops);
    }
    write(ans, "\n");
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int tc = 1;
    read(tc);
    for (int curr = 1; curr <= tc; curr++) solve(curr);
    return 0;
}