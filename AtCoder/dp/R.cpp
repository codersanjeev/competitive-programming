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

vector<vector<int>> multiply(const vector<vector<int>> &X, const vector<vector<int>> &Y) {
    int n = X.size();
    vector<vector<int>> ans(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                ans[i][j] = (ans[i][j] + (X[i][k] * Y[k][j])) % MOD;
            }
        }
    }
    return ans;
}

vector<vector<int>> solve(const vector<vector<int>> &arr, int k) {
    if (k == 0) {
        int n = arr.size();
        vector<vector<int>> ans(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) ans[i][i] = 1;
        return ans;
    }
    if (k == 1) {
        return arr;
    }
    if (k % 2 == 0) {
        vector<vector<int>> temp = multiply(arr, arr);
        return solve(temp, k / 2);
    } else {
        vector<vector<int>> temp = multiply(arr, arr);
        return multiply(solve(temp, k / 2), arr);
    }
}

void solve(int tc) {
    int n, k;
    read(n, k);
    vector<vector<int>> arr(n, vector<int>(n));
    for (auto &ele : arr) readContainer(ele);
    arr = solve(arr, k);
    int ans = 0;
    for (const auto &ele : arr) {
        for (const auto &x : ele) {
            ans = (ans + x) % MOD;
        }
    }
    write(ans, "\n");
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