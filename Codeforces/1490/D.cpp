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

class TreeNode {
   public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

int findMaxElementIndex(const vector<int> &arr, int i, int j) {
    int ans = -1, mx = INT_MIN;
    for (int k = i; k <= j; k++) {
        mx = max(mx, arr[k]);
    }
    for (int k = i; k <= j; k++) {
        if (arr[k] == mx) {
            ans = k;
            break;
        }
    }
    return ans;
}

TreeNode *buildTree(const vector<int> &arr, int i, int j) {
    if (i > j) {
        return nullptr;
    }
    int index = findMaxElementIndex(arr, i, j);
    TreeNode *root = new TreeNode(arr[index]);
    root->left = buildTree(arr, i, index - 1);
    root->right = buildTree(arr, index + 1, j);
    return root;
}

unordered_map<int, int> ans;

void dfs(TreeNode *root, int level = 0) {
    if (root == nullptr) {
        return;
    }
    ans[root->data] = level;
    dfs(root->left, level + 1);
    dfs(root->right, level + 1);
}

void solve(int tc) {
    int n;
    read(n);
    vector<int> arr(n);
    readContainer(arr);
    TreeNode *root = buildTree(arr, 0, n - 1);
    dfs(root);
    for (const auto &ele : arr) {
        write(ans[ele], " ");
    }
    write("\n");
}

signed main() {
    int tc = 1;
    read(tc);
    for (int curr = 1; curr <= tc; curr++) {
        solve(curr);
    }
    return 0;
}