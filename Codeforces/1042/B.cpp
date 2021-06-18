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

int getStringMask(string &s) {
    int ans = 0, pos = 0;
    for (char ch = 'C'; ch >= 'A'; ch--) {
        if (s.find(ch) != string::npos) {
            ans += (1 << pos);
        }
        pos++;
    }
    return ans;
}

void solve(int tc) {
    int n;
    read(n);
    vector<int> C(n);
    vector<string> S(n);
    for (int i = 0; i < n; i++) {
        read(C[i], S[i]);
    }
    vector<vector<int>> dp(n + 1, vector<int>(8, 1e9));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        int stringMask = getStringMask(S[i]);
        // deb(stringMask);
        for (int mask = 0; mask < 8; mask++) {
            dp[i + 1][mask] = min(dp[i + 1][mask], dp[i][mask]);
            dp[i + 1][mask | stringMask] = min(dp[i + 1][mask | stringMask], dp[i][mask] + C[i]);
        }
    }
    if (dp[n][7] == 1e9) {
        write(-1);
    } else {
        write(dp[n][7]);
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int tc = 1;
    // read(tc);
    for (int curr = 1; curr <= tc; curr++) solve(curr);
    return 0;
}