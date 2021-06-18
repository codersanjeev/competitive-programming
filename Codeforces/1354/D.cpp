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

struct FenwickTree {
    int N;
    vector<int> tree;

    void init(int n) {
        N = n;
        tree.assign(n + 1, 0);
    }

    void update(int idx, int val) {
        while (idx <= N) {
            tree[idx] += val;
            idx += idx & -idx;
        }
    }

    void updateMax(int idx, int val) {
        while (idx <= N) {
            tree[idx] = max(tree[idx], val);
            idx += idx & -idx;
        }
    }

    int pref(int idx) {
        int ans = 0;
        while (idx > 0) {
            ans += tree[idx];
            idx -= idx & -idx;
        }
        return ans;
    }

    int rsum(int l, int r) {
        return pref(r) - pref(l - 1);
    }

    int prefMax(int idx) {
        int ans = -2e9;
        while (idx > 0) {
            ans = max(ans, tree[idx]);
            idx -= idx & -idx;
        }
        return ans;
    }
};

void solve(int tc) {
    int n, q;
    read(n, q);

    FenwickTree bit;
    bit.init(n);

    for (int i = 0; i < n; ++i) {
        int x;
        read(x);
        bit.update(x, 1);
    }

    while (q--) {
        int k;
        read(k);

        if (k >= 1) {
            bit.update(k, 1);
        }

        else {
            k = -k;

            int beg = 1, end = n;
            int ans;

            while (beg <= end) {
                int mid = (beg + end) / 2;

                int cur_pref = bit.pref(mid);

                if (cur_pref >= k)
                    ans = mid, end = mid - 1;

                else
                    beg = mid + 1;
            }

            bit.update(ans, -1);
        }
    }

    int ans = 0;

    for (int i = 1; i <= n; ++i)
        if (bit.pref(i)) {
            ans = i;
            break;
        }

    write(ans);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int tc = 1;
    // read(tc);
    for (int curr = 1; curr <= tc; curr++) solve(curr);
    return 0;
}