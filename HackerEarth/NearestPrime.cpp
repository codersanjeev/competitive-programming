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

template <typename T>
void readContainer(T &t) {
    for (auto &e : t) read(e);
}

template <typename T>
void writeContainer(T &t) {
    for (const auto &e : t) write(e, " ");
    write("\n");
}

bitset<10000010> isPrime;
vector<int> primeNumbers;

void sieve(int _sieve_size) {
    isPrime.set();
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i <= _sieve_size; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= _sieve_size; j += i) {
                isPrime[j] = 0;
            }
            primeNumbers.push_back(i);
        }
    }
}

void solve(int tc) {
    int n;
    read(n);
    auto it = lower_bound(primeNumbers.begin(), primeNumbers.end(), n);
    int x = *it;
    it--;
    int y = *it;
    if (abs(x - n) < abs(y - n)) {
        write(x, "\n");
    } else {
        write(y, "\n");
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
    sieve(10000000);
    read(tc);
    for (int curr = 1; curr <= tc; curr++) solve(curr);
    return 0;
}