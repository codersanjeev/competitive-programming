#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")

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
    cout.tie(nullptr);
    return nullptr;
}();

const int MAX = 4e5 + 4;
vector<int> P(MAX, 0);

void solve(int tc) {
    for (int i = 0; i < MAX; i++) {
        P[i] = 0;
    }
    int N, Q, M, Li, Ri;
    read(N, Q, M);
    vector<int> A(N);
    readContainer(A);
    map<pair<int, int>, int> myMap;
    while (Q--) {
        read(Li, Ri);
        if (A[Li - 1] > M) {
            continue;
        } else if (A[Li - 1] <= M && A[Ri - 1] > M) {
            P[A[Li - 1]]++;
            P[M + 1]--;
        } else {
            P[A[Li - 1]]++;
            P[M + 1]--;
            myMap[{A[Li - 1], A[Ri - 1]}]++;
        }
    }
    for (const auto &ele : myMap) {
        Li = ele.first.first;
        Ri = ele.first.second;
        P[Li + Ri] -= ele.second;
        P[2 * Li + Ri] += ele.second;
        int lim = 2 * Li + Ri;
        while (lim + Ri <= M) {
            lim += Ri;
            P[lim] -= ele.second;
            P[lim + Li] += ele.second;
            lim += Li;
        }
    }
    int answer = 0;
    for (int i = 1; i <= M; i++) {
        P[i] += P[i - 1];
        answer = max(answer, P[i]);
    }
    write(answer, "\n");
}

signed main() {
    int tc = 1;
    read(tc);
    for (int curr = 1; curr <= tc; curr++) {
        solve(curr);
    }
    return 0;
}