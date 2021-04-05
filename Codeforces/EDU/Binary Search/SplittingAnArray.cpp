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

auto speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

int numberOfSegments(const vector<int> &arr, int x) {
    int cnt = 1, curr = 0;
    for (const auto &ele : arr) {
        curr += ele;
        if (curr > x) {
            cnt++;
            curr = ele;
        }
    }
    return cnt;
}

int splitArray(vector<int> &A, int K) {
    int lo = *max_element(A.begin(), A.end()), hi = accumulate(A.begin(), A.end(), 0LL);
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        int segments = numberOfSegments(A, mid);
        if (segments <= K) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return lo;
}

void solve(int tc) {
    int N, K;
    read(N, K);
    vector<int> A(N);
    readContainer(A);
    write(splitArray(A, K));
}

signed main() {
    int tc = 1;
    // read(tc);
    for (int curr = 1; curr <= tc; ++curr) {
        solve(curr);
    }
    return 0;
}