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

void solve(int tc) {
    int h, w, n, m, ai, bi, ci, di;
    read(h, w, n, m);
    vector<vector<int>> arr(h, vector<int>(w, 0));
    // 0 -> empty
    // 1 -> bulb
    // 2 -> block
    for (int i = 0; i < n; i++) {
        cin >> ai >> bi;
        ai--;
        bi--;
        arr[ai][bi] = 1;
    }
    for (int i = 0; i < m; i++) {
        cin >> ci >> di;
        ci--;
        di--;
        arr[ci][di] = 2;
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (arr[i][j] == 1) {
                // top
                int x = i - 1, y = j;
                while (x >= 0 && arr[x][y] != 2 && arr[x][y] != 1) {
                    arr[x][y] = 3;
                    x--;
                }
                // left
                x = i, y = j - 1;
                while (y >= 0 && arr[x][y] != 2 && arr[x][y] != 1) {
                    arr[x][y] = 3;
                    y--;
                }
                // bottom
                x = i + 1, y = j;
                while (x < h && arr[x][y] != 2 && arr[x][y] != 1) {
                    arr[x][y] = 3;
                    x++;
                }
                // right
                x = i, y = j + 1;
                while (y < w && arr[x][y] != 2 && arr[x][y] != 1) {
                    arr[x][y] = 3;
                    y++;
                }
            }
        }
    }
    int ans = 0;
    for (const auto &row : arr) {
        for (const auto &ele : row) {
            if (ele == 3 || ele == 1) ans++;
        }
    }
    write(ans);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    int tc = 1;
    // read(tc);
    for (int curr = 1; curr <= tc; curr++) solve(curr);
    return 0;
}