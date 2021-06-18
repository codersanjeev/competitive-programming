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

void reverse(string &s, int i, int j) {
    while (i < j) {
        swap(s[i], s[j]);
        ++i;
        --j;
    }
}

void solve(int tc) {
    int n, q, ti, ai, bi;
    string s;
    read(n, s, q);
    bool flag = false;
    while (q--) {
        read(ti, ai, bi);
        if (ti == 2) {
            flag = !flag;
        } else {
            if (!flag) {
                swap(s[ai - 1], s[bi - 1]);
            } else {
                if (ai <= n)
                    ai += n;
                else
                    ai -= n;
                if (bi <= n)
                    bi += n;
                else
                    bi -= n;
                swap(s[ai - 1], s[bi - 1]);
            }
        }
    }
    if (flag) {
        reverse(s, 0, n - 1);
        reverse(s, n, (2 * n) - 1);
        reverse(s, 0, (2 * n) - 1);
    }
    write(s);
}

signed main() {
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    // read(tc);
    for (int curr = 1; curr <= tc; ++curr) {
        solve(curr);
    }
    return 0;
}