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

int calculateWords(const set<string> &l1, const set<string> &l2) {
    int ans = 0;
    for (const auto &x : l1) {
        if (l2.count(x) == 0) {
            for (const auto &y : l2) {
                if (l1.count(y) == 0) {
                    ans += 2;
                }
            }
        }
    }
    return ans;
}

void solve(int tc) {
    int n;
    read(n);
    vector<string> arr(n);
    readContainer(arr);
    map<char, set<string>> mp;
    for (const auto &ele : arr) {
        mp[ele[0]].insert(ele.substr(1));
    }
    vector<set<string>> store;
    for (const auto &ele : mp) {
        store.push_back(ele.second);
    }
    // for (const auto &ele : store) {
    // 	writeContainer(ele);
    // }
    // write("\n");
    n = store.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ans += calculateWords(store[i], store[j]);
        }
    }
    write(ans, "\n");
}

signed main() {
    int tc = 1;
    read(tc);
    for (int curr = 1; curr <= tc; curr++) {
        solve(curr);
    }
    return 0;
}