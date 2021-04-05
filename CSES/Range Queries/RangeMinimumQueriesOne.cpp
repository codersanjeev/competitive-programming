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

// size of tree = 4 * N + 1, where N = size of input array
vector<int> tree;
vector<int> arr;

// index: initial index of tree = 1
// [start, end]: range of size of input array
void buildTree(int index, int start, int end) {
    if (start > end) {
        return;
    }
    if (start == end) {
        tree[index] = arr[start];
        return;
    }
    int mid = start + (end - start) / 2;
    buildTree(2 * index, start, mid);
    buildTree(2 * index + 1, mid + 1, end);
    tree[index] = min(tree[2 * index], tree[2 * index + 1]);
}

// find the answer for [left, right] query
// tree[index] contains the answer for [start, end]
int queryTree(int index, int start, int end, int left, int right) {
    if (left > end || right < start) {
        return LLONG_MAX;
    }
    if (left <= start && end <= right) {
        return tree[index];
    }
    int mid = start + (end - start) / 2;
    return min(queryTree(2 * index, start, mid, left, right), queryTree(2 * index + 1, mid + 1, end, left, right));
}

void solve(int tc) {
    int N, Q, L, R;
    read(N, Q);
    arr.resize(N);
    tree.resize(4 * N + 1);
    readContainer(arr);
    buildTree(1, 0, N - 1);
    while (Q--) {
        read(L, R);
        L--;
        R--;
        write(queryTree(1, 0, N - 1, L, R), "\n");
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