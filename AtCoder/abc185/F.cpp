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

const int MAX = 300001 * 8;
vector<int> tree(MAX);
vector<int> ar;

int constSegTree(int strt, int end, int idx) {
    if (strt == end) return tree[idx] = ar[strt];
    int mid = (strt + end) / 2;
    return tree[idx] = constSegTree(strt, mid, 2 * idx + 1) ^ constSegTree(mid + 1, end, 2 * idx + 2);
}
void constSegTree(int n) {
    constSegTree(0, n - 1, 0);
}

int getXor(int strt, int end, int l, int r, int idx) {
    if (strt <= l && r <= end)
        return tree[idx];

    if (end < l || r < strt || l > r)
        return 0;

    int mid = (l + r) / 2;
    return getXor(strt, end, l, mid, 2 * idx + 1) ^ getXor(strt, end, mid + 1, r, 2 * idx + 2);
}

int getXor(int n, int strt, int end) {
    return getXor(strt, end, 0, n - 1, 0);
}

void updtNode(int pos, int val, int l, int r, int idx) {
    if (pos < l || r < pos)
        return;
    if (l == r) {
        tree[idx] ^= val;
        return;
    }
    int mid = (l + r) / 2;
    updtNode(pos, val, l, mid, 2 * idx + 1);
    updtNode(pos, val, mid + 1, r, 2 * idx + 2);
    tree[idx] = tree[2 * idx + 1] ^ tree[2 * idx + 2];
}

void updtNode(int n, int pos, int val) {
    updtNode(pos, val, 0, n - 1, 0);
}

void solve(int tc) {
    int N, Q, Ti, Xi, Yi;
    read(N, Q);
    ar.resize(N);
    readContainer(ar);
    constSegTree(N);
    while (Q--) {
        read(Ti, Xi, Yi);
        if (Ti == 1) {
            updtNode(N, Xi - 1, Yi);
        } else {
            write(getXor(N, Xi - 1, Yi - 1), "\n");
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    int tc = 1;
    // read(tc);
    for (int curr = 1; curr <= tc; curr++) solve(curr);
    return 0;
}