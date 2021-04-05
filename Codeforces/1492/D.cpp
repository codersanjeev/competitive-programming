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
        write(e, "");
    }
    write("\n");
}

auto speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

void solve(int tc) {
    int A, B, K;
    read(A, B, K);
    int N = A + B;
    vector<char> S(N, '0'), P(N, '0');
    if (K == 0) {
        for (int i = 0; i < B; i++) {
            S[i] = P[i] = '1';
        }
        write("Yes\n");
        writeContainer(S);
        writeContainer(P);
        return;
    }
    if (A == 0 || B == 1 || K >= N - 1) {
        write("No\n");
        return;
    }
    S[0] = P[0] = S[1] = P[1 + K] = '1';
    B -= 2;
    int i = 2;
    while (B > 0 && i < N) {
        if (i == 1 + K) {
            i++;
            continue;
        }
        S[i] = P[i] = '1';
        i++;
        B--;
    }
    write("Yes\n");
    writeContainer(S);
    writeContainer(P);
}

signed main() {
    int tc = 1;
    // read(tc);
    for (int curr = 1; curr <= tc; ++curr) {
        solve(curr);
    }
    return 0;
}