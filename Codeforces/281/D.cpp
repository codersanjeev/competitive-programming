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
    cout.tie(nullptr);
    return nullptr;
}();

void solve(int tc) {
    int n;
    read(n);
    vector<int> arr(n);
    readContainer(arr);
    int ans = arr[0] ^ arr[1];
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top() < arr[i]) {
            st.pop();
        }
        st.push(arr[i]);
        if (st.size() >= 2) {
            int x = st.top();
            st.pop();
            int y = st.top();
            st.push(x);
            ans = max(ans, x ^ y);
        }
    }
    while (!st.empty()) {
        st.pop();
    }
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() < arr[i]) {
            st.pop();
        }
        st.push(arr[i]);
        if (st.size() >= 2) {
            int x = st.top();
            st.pop();
            int y = st.top();
            st.push(x);
            ans = max(ans, x ^ y);
        }
    }
    write(ans);
}

signed main() {
    int tc = 1;
    // read(tc);
    for (int curr = 1; curr <= tc; curr++) {
        solve(curr);
    }
    return 0;
}