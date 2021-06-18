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

struct segtree {
    segtree(const vector<int> &arr) {
        _arr = arr;
        _N = arr.size();
        _oddTree.resize(4 * _N + 1);
        _evenTree.resize(4 * _N + 1);
        buildTree(1, 0, _N - 1);
    }

    int queryOdd(int L, int R) {
        return queryTreeOdd(1, 0, _N - 1, L, R);
    }

    int queryEven(int L, int R) {
        return queryTreeEven(1, 0, _N - 1, L, R);
    }

    void update(int index, int ele) {
        updateTree(1, 0, _N - 1, index, ele);
    }

   private:
    int _N;
    vector<int> _arr, _oddTree, _evenTree;

    void buildTree(int index, int start, int end) {
        if (start > end) {
            return;
        }
        if (start == end) {
            _oddTree[index] = (_arr[start] % 2 == 1);
            _evenTree[index] = (_arr[start] % 2 == 0);
            return;
        }
        int mid = start + (end - start) / 2;
        buildTree(2 * index, start, mid);
        buildTree(2 * index + 1, mid + 1, end);
        _oddTree[index] = _oddTree[2 * index] + _oddTree[2 * index + 1];
        _evenTree[index] = _evenTree[2 * index] + _evenTree[2 * index + 1];
    }

    int queryTreeOdd(int index, int start, int end, int left, int right) {
        if (left > end || right < start) {
            return 0;
        }
        if (left <= start && end <= right) {
            return _oddTree[index];
        }
        int mid = start + (end - start) / 2;
        int L = queryTreeOdd(2 * index, start, mid, left, right);
        int R = queryTreeOdd(2 * index + 1, mid + 1, end, left, right);
        return L + R;
    }

    int queryTreeEven(int index, int start, int end, int left, int right) {
        if (left > end || right < start) {
            return 0;
        }
        if (left <= start && end <= right) {
            return _evenTree[index];
        }
        int mid = start + (end - start) / 2;
        int L = queryTreeEven(2 * index, start, mid, left, right);
        int R = queryTreeEven(2 * index + 1, mid + 1, end, left, right);
        return L + R;
    }

    void updateTree(int index, int start, int end, int idx, int val) {
        if (idx < start || idx > end) {
            return;
        }
        if (start == end) {
            _oddTree[index] = (val % 2 == 1);
            _evenTree[index] = (val % 2 == 0);
            return;
        }
        int mid = start + (end - start) / 2;
        updateTree(2 * index, start, mid, idx, val);
        updateTree(2 * index + 1, mid + 1, end, idx, val);
        _oddTree[index] = _oddTree[2 * index] + _oddTree[2 * index + 1];
        _evenTree[index] = _evenTree[2 * index] + _evenTree[2 * index + 1];
    }
};

void solve(int tc) {
    int N, T, X, Y, Q;
    read(N);
    vector<int> A(N);
    readContainer(A);
    segtree *tree = new segtree(A);
    read(Q);
    while (Q--) {
        read(T, X, Y);
        if (T == 0) {
            tree->update(X - 1, Y);
        } else if (T == 1) {
            write(tree->queryEven(X - 1, Y - 1), "\n");
        } else {
            write(tree->queryOdd(X - 1, Y - 1), "\n");
        }
    }
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