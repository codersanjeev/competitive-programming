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

int snakesAndLadders(vector<int> &arr) {
    int n = arr.size();
    vector<bool> visited(n, false);
    queue<pair<int, int>> q;
    q.push({0, 0});
    while (!q.empty()) {
        auto curr = q.front();
        q.pop();
        int u = curr.first;
        int d = curr.second;
        if (u == n - 1) {
            return d;
        }
        visited[u] = true;
        for (int i = 1; i <= 6; i++) {
            int ni = u + i;
            if (ni < n && arr[ni] != -1) {
                ni = arr[ni] - 1;
            }
            if (ni >= n) {
                continue;
            }
            if (ni == n - 1 || visited[ni] == false) {
                q.push({ni, d + 1});
            }
        }
    }
    return -1;
}

void solve(int tc) {
    vector<int> board(100, -1);
    int N, M, u, v;
    read(N);
    while (N--) {
        read(u, v);
        board[u - 1] = v;
    }
    read(M);
    while (M--) {
        read(u, v);
        board[u - 1] = v;
    }
    write(snakesAndLadders(board), "\n");
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int tc = 1;
    read(tc);
    for (int curr = 1; curr <= tc; curr++) solve(curr);
    return 0;
}