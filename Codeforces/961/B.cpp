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
    int n, k;
    read(n, k);
    vector<int> A(n), T(n);
    readContainer(A);
    readContainer(T);
    vector<int> pre(n), pos(n), P(n);
    pre[0] = A[0] * T[0];
    P[0] = A[0];
    pos[n - 1] = A[n - 1] * T[n - 1];
    for (int i = 1; i < n; i++) {
        pre[i] = pre[i - 1] + (A[i] * T[i]);
        P[i] = P[i - 1] + A[i];
    }
    for (int i = n - 2; i >= 0; i--) {
        pos[i] = pos[i + 1] + (A[i] * T[i]);
    }
    int ans = INT_MIN;
    for (int i = 0; i <= n - k; i++) {
        // pre[0, i - 1] + P[i, i + k - 1] + pos[i + k, n - 1]
        int curr = P[i + k - 1];
        if (i > 0) {
            curr -= P[i - 1];
            curr += pre[i - 1];
        }
        if (i + k < n) {
            curr += pos[i + k];
        }
        ans = max(ans, curr);
    }
    write(ans);
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