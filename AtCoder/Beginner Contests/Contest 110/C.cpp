#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("trapv")
#pragma GCC target("sse4")

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define deb(x) cout << #x << " is " << x << "\n"
#define int long long
#define MOD 1000000007LL
#define mod(x) (x % MOD + MOD) % MOD
#define PI acos(-1)

template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

template <typename T>
using max_heap = priority_queue<T>;

template <class T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
    string S, T;
    read(S, T);
    int N = S.size();
    unordered_map<int, int> mp, imp;
    bool ok = true;

    for (int i = 0; i < N; i++) {
        if (mp[S[i]] > 0 && mp[S[i]] != T[i]) {
            ok = false;
            break;
        }

        if (imp[T[i]] > 0 && imp[T[i]] != S[i]) {
            ok = false;
            break;
        }

        mp[S[i]] = T[i];
        imp[T[i]] = S[i];
    }

    write((ok ? "Yes" : "No"));
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    // 	freopen("input.txt", "r", stdin);
    // 	freopen("output.txt", "w", stdout);
    // #endif
    int tc = 1;
    // read(tc);

    for (int curr = 1; curr <= tc; curr++) solve(curr);

    return 0;
}