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
    vector<int> A(N);
    readContainer(A);
    sort(A.begin(), A.end());
    int sm = accumulate(A.begin(), A.end(), 0LL);
    int mx = *max_element(A.begin(), A.end());
    if (mx <= (sm - mx)) {
        write(sm);
        return;
    }
    vector<int> B = A;
    for (int i = 1; i < N; i++) {
        A[i] += A[i - 1];
    }
    for (int i = N - 2; i >= 0; i--) {
        B[i] += B[i + 1];
    }
    int ans = B[0];
    for (int i = 1; i < N; i++) {
        ans = min(ans, max(A[i - 1], B[i]));
    }
    write(ans * 2);
}

signed main() {
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