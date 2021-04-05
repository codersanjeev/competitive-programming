#pragma GCC optimize("O3")
#pragma GCC target("sse4")

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

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

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve(int tc) {
    int N, K;
    read(N, K);
    vector<int> X(N);
    readContainer(X);
    ordered_set st;

    for (int i = 0; i < K; i++) {
        st.insert(X[i]);
    }

    int med = *st.find_by_order(((K + 1) / 2) - 1);
    int ans = 0;

    for (int i = 0; i < K; i++) {
        ans += abs(X[i] - med);
    }

    write(ans, " ");

    for (int i = 0; i < N - K; i++) {
        st.erase(st.find_by_order(st.order_of_key(X[i])));
        st.insert(X[i + K]);
        int nmed = *st.find_by_order(((K + 1) / 2) - 1);
        ans += abs(nmed - X[i + K]) - abs(med - X[i]);

        if (K % 2 == 0) {
            ans -= (nmed - med);
        }

        med = nmed;
        write(ans, " ");
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