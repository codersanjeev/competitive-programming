#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("fast-math")

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define deb(x) cout << #x << " is " << x << "\n"
#define int long long
#define MOD 1000000007LL
#define PI acos(-1)

template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

template <typename T>
using max_heap = priority_queue<T>;

template <class T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
    for (auto &e : t) {
        read(e);
    }
}

template <typename T>
void writeContainer(T &t) {
    for (const auto &e : t) {
        write(e, " ");
    }
    write("\n");
}

auto speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

const int N = 5e5 + 5;
vector<bool> isprime(N + 1, true);
vector<int> primes;

void generatePrimes() {
    isprime[1] = false;
    for (int i = 2; i * i <= N; i++) {
        if (isprime[i]) {
            for (int j = 2 * i; j <= N; j += i) {
                isprime[j] = false;
            }
        }
    }
    for (int i = 2; i <= N; i++) {
        if (isprime[i]) {
            primes.push_back(i);
        }
    }
}

int f(int x) {
    int lo = 0, hi = primes.size() - 1, ans = 2;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (primes[mid] > x) {
            ans = primes[mid];
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return ans;
}

void solve(int tc) {
    int d;
    read(d);
    int x = f(d);
    int y = f(x + d - 1);
    write(x * y, "\n");
}

signed main() {
    int tc = 1;
    generatePrimes();
    read(tc);
    for (int curr = 1; curr <= tc; ++curr) {
        solve(curr);
    }
    return 0;
}