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
        _tree.resize(4 * _N + 1);
        buildTree(1, 0, _N - 1);
    }

    int query(int L, int R) {
        return queryTree(1, 0, _N - 1, L, R);
    }

    void update(int index, int ele) {
        updateTree(1, 0, _N - 1, index, ele);
    }

   private:
    int _N;
    vector<int> _arr, _tree;

    void buildTree(int index, int start, int end) {
        if (start > end) {
            return;
        }

        if (start == end) {
            _tree[index] = _arr[start];
            return;
        }

        int mid = start + (end - start) / 2;
        buildTree(2 * index, start, mid);
        buildTree(2 * index + 1, mid + 1, end);
        int L = _tree[2 * index];
        int R = _tree[2 * index + 1];
        _tree[index] = mergeNodes(L, R);
    }

    int queryTree(int index, int start, int end, int left, int right) {
        if (left > end || right < start) {
            return LLONG_MIN;
        }

        if (left <= start && end <= right) {
            return _tree[index];
        }

        int mid = start + (end - start) / 2;
        int L = queryTree(2 * index, start, mid, left, right);
        int R = queryTree(2 * index + 1, mid + 1, end, left, right);
        return mergeNodes(L, R);
    }

    void updateTree(int index, int start, int end, int idx, int val) {
        if (idx < start || idx > end) {
            return;
        }

        if (start == end) {
            _tree[index] -= val;
            return;
        }

        int mid = start + (end - start) / 2;
        updateTree(2 * index, start, mid, idx, val);
        updateTree(2 * index + 1, mid + 1, end, idx, val);
        int L = _tree[2 * index];
        int R = _tree[2 * index + 1];
        _tree[index] = mergeNodes(L, R);
    }

    int mergeNodes(int left, int right) {
        return max(left, right);
    }
};

void solve(int tc) {
    int N, Q, X;
    read(N, Q);
    vector<int> A(N);
    readContainer(A);
    segtree *tree = new segtree(A);

    while (Q--) {
        read(X);
        int lo = 0, hi = N - 1, ans = -1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int curr = tree->query(lo, mid);

            if (curr >= X) {
                ans = mid;
                hi = mid - 1;

            } else {
                lo = mid + 1;
            }
        }

        if (ans == -1) {
            write("0 ");

        } else {
            tree->update(ans, X);
            write(ans + 1, " ");
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