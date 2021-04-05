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
#define MOD 10000007LL
#define PI acos(-1)

template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

template <typename T>
using max_heap = priority_queue<T>;

template <class T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

// template <typename... T>
// void read(T &...args) {
//     ((cin >> args), ...);
// }

// template <typename... T>
// void write(T &&...args) {
//     ((cout << args), ...);
// }

// template <typename T>
// void readContainer(T &t) {
//     for (auto &e : t) {
//         read(e);
//     }
// }

// template <typename T>
// void writeContainer(T &t) {
//     for (const auto &e : t) {
//         write(e, " ");
//     }
//     write("\n");
// }

auto speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

int binpow(int x, int y, int z) {
    x = x % z;
    int ans = 1LL;
    while (y > 0) {
        if (y % 2 == 1) {
            ans = (ans * x) % z;
        }
        x = (x * x) % z;
        y = y / 2;
    }
    return ans;
}

void solve(int tc) {
    // 2*(n-1)^k + n^k + 2*(n-1)^(n-1) + n^n
    int n, k;
    while (1) {
        cin >> n >> k;
        if (n == 0 && k == 0) {
            break;
        }
        int ans = binpow(n - 1, k, MOD);
        ans = (ans * 2) % MOD;
        ans = (ans + binpow(n, k, MOD)) % MOD;
        ans = (ans + binpow(n, n, MOD)) % MOD;
        int temp = binpow(n - 1, n - 1, MOD);
        temp = (temp * 2) % MOD;
        ans = (ans + temp) % MOD;
        cout << ans << "\n";
    }
}

signed main() {
    int tc = 1;
    // read(tc);
    for (int curr = 1; curr <= tc; curr++) {
        solve(curr);
    }
    return 0;
}