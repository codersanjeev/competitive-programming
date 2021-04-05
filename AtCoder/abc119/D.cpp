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

int f(int qx, int sx, int tx) {
    return min(abs(qx - sx) + abs(sx - tx), abs(qx - tx) + abs(tx - sx));
}

void solve(int tc) {
    int A, B, Q;
    read(A, B, Q);
    vector<int> S(A), T(B);
    for (int i = 0; i < A; i++) read(S[i]);
    for (int j = 0; j < B; j++) read(T[j]);
    for (int qi = 0; qi < Q; qi++) {
        int qx;
        read(qx);
        auto si = lower_bound(S.begin(), S.end(), qx);
        int sx1, sx2;
        if (si == S.end()) --si;
        if (si == S.begin())
            sx1 = *si;
        else {
            sx1 = *(--si);
            ++si;
        }
        sx2 = *si;

        auto ti = lower_bound(T.begin(), T.end(), qx);
        int tx1, tx2;
        if (ti == T.end()) --ti;
        if (ti == T.begin())
            tx1 = *ti;
        else {
            tx1 = *(--ti);
            ++ti;
        }
        tx2 = *ti;
        write(min({f(qx, sx1, tx1), f(qx, sx1, tx2), f(qx, sx2, tx1), f(qx, sx2, tx2)}), "\n");
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    int tc = 1;
    // read(tc);
    for (int curr = 1; curr <= tc; curr++) solve(curr);
    return 0;
}