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

// template <typename... T>
// void read(T &...args) {
//  ((cin >> args), ...);
// }

// template <typename... T>
// void write(T &&...args) {
//  ((cout << args), ...);
// }

// template <typename T>
// void readContainer(T &t) {
//  for (auto &e : t) {
//      read(e);
//  }
// }

// template <typename T>
// void writeContainer(T &t) {
//  for (const auto &e : t) {
//      write(e, " ");
//  }
//  write("\n");
// }

auto speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

int trapRainWater(vector<vector<int>> &matrix) {
    int n = matrix.size(), m = matrix[0].size(), ans = 0;
    vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                if (matrix[i][j] != -1) {
                    pq.push({matrix[i][j], {i, j}});
                    matrix[i][j] = -1;
                }
            }
        }
    }
    while (!pq.empty()) {
        auto curr = pq.top();
        pq.pop();
        int h = curr.first;
        int i = curr.second.first;
        int j = curr.second.second;
        for (int k = 0; k < 4; k++) {
            int nx = i + dirs[k].first;
            int ny = j + dirs[k].second;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && matrix[nx][ny] != -1) {
                ans += max(0LL, h - matrix[nx][ny]);
                pq.push({max(h, matrix[nx][ny]), {nx, ny}});
                matrix[nx][ny] = -1;
            }
        }
    }
    return ans;
}

void solve(int tc) {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> arr(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }
    int ans = trapRainWater(arr);
    cout << ans << "\n";
}

signed main() {
    int tc = 1;
    cin >> tc;
    for (int curr = 1; curr <= tc; ++curr) {
        solve(curr);
    }
    return 0;
}