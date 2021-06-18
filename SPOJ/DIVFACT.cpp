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

const int N = 50001;
bitset<N> isprime;
vector<int> primes;

void sieve() {
    isprime.set();
    for (int i = 2; i < N; i++) {
        if (isprime[i]) {
            for (int j = i * i; j < N; j += i) {
                isprime[j] = 0;
            }
            primes.push_back(i);
        }
    }
}

void solve(int tc) {
    int n, ans = 1;
    read(n);
    for (const auto &ele : primes) {
        if (ele > n) {
            break;
        }
        int p = ele, cnt = 0;
        while (n / p > 0) {
            cnt += (n / p);
            p *= ele;
        }
        ans = (ans * (cnt + 1)) % mod;
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
    sieve();
    int tc = 1;
    read(tc);
    for (int curr = 1; curr <= tc; curr++) solve(curr);
    return 0;
}