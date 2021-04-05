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

struct Node {
    Node *children[26];
    int cnt = 0;
};

Node *root;
int ans;

void insert(const string &s) {
    Node *curr = root;
    for (const auto &ch : s) {
        int index = ch - 'A';
        if (curr->children[index] == nullptr) {
            curr->children[index] = new Node();
        }
        curr = curr->children[index];
    }
    curr->cnt++;
}

void dfs(Node *curr, int level, int k) {
    for (const auto &child : curr->children) {
        if (child == nullptr) {
            continue;
        }
        dfs(child, level + 1, k);
        curr->cnt += child->cnt;
    }
    while (curr->cnt >= k) {
        curr->cnt -= k;
        ans += level;
    }
}

void solve(int tc) {
    int N, K;
    read(N, K);
    vector<string> S(N);
    readContainer(S);
    root = new Node();
    for (const auto &ele : S) {
        insert(ele);
    }
    ans = 0;
    dfs(root, 0, K);
    write("Case #", tc, ": ", ans, "\n");
}

signed main() {
    int tc = 1;
    read(tc);
    for (int curr = 1; curr <= tc; curr++) {
        solve(curr);
    }
    return 0;
}