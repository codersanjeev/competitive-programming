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
    int N;
    read(N);
    vector<int> W(N);
    readContainer(W);
    unordered_map<int, int> mp;
    for (const auto &ele : W) mp[ele]++;
    int ans = 0;
    for (int i = 2; i < 2 * N + 1; i++) {
        int curr = 0;
        for (int j = 1; j < (i + 1) / 2; j++) {
            curr += min(mp[j], mp[i - j]);
        }
        if (i % 2 == 0) curr += mp[i / 2] / 2;
        ans = max(ans, curr);
    }
    write(ans, "\n");
}

signed main() {
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