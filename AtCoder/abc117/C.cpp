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
void read(T &...args) {
    ((cin >> args), ...);
}

template <typename... T>
void write(T &&...args) {
    ((cout << args), ...);
}

void solve(int tc) {
    int N, M;
    read(N, M);
    vector<int> X(M);
    for (auto &ele : X) read(ele);
    if (N >= M)
        write(0);
    else {
        sort(X.begin(), X.end());
        vector<int> Y;
        for (int i = 1; i < M; i++) Y.push_back(X[i] - X[i - 1]);
        sort(Y.begin(), Y.end());
        int ans = 0;
        for (int i = 0; i < M - N; i++) ans += Y[i];
        write(ans);
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