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

const int M = 2e5 + 1;
const int MOD = 998244353;
vector<int> fib(M), invpow(M);

int modpow(int a, int b, int m) {
    a %= m;
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void preprocessing() {
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < M; i++) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
    }
    int curr = 1;
    for (int i = 0; i < M; i++) {
        invpow[i] = modpow(curr, MOD - 2, MOD);
        curr = (curr * 2) % MOD;
    }
}

void solve(int tc) {
    int N;
    read(N);
    write((fib[N] * invpow[N]) % MOD, "\n");
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int tc = 1;
    preprocessing();
    // read(tc);
    for (int curr = 1; curr <= tc; curr++) solve(curr);
    return 0;
}