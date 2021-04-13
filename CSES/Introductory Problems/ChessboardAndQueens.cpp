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

vector<vector<int>> board(8, vector<int>(8, 0));
int ans = 0;

bool isSafePlace(int i, int j) {
    if (i < 0 || j < 0 || i >= 8 || j >= 8 || board[i][j] == -1) return false;
    for (int k = 0; k < 8; ++k) {
        if (board[i][k] == 1) return false;
        if (board[k][j] == 1) return false;
    }
    int x = i, y = j;
    while (x >= 0 && y >= 0) {
        if (board[x][y] == 1) return false;
        --x;
        --y;
    }
    x = i;
    y = j;
    while (x >= 0 && y < 8) {
        if (board[x][y] == 1) return false;
        --x;
        ++y;
    }
    return true;
}

bool solveNQueen(int i) {
    if (i == 8) {
        ++ans;
        return false;
    }
    for (int j = 0; j < 8; ++j) {
        if (isSafePlace(i, j)) {
            board[i][j] = 1;
            if (solveNQueen(i + 1)) return true;
            board[i][j] = 0;
        }
    }
    return false;
}

void solve(int tc) {
    char ch;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            cin >> ch;
            if (ch == '*') {
                board[i][j] = -1;
            }
        }
    }
    ans = 0;
    solveNQueen(0);
    write(ans, "\n");
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    // read(tc);
    for (int curr = 1; curr <= tc; ++curr) {
        solve(curr);
    }
    return 0;
}