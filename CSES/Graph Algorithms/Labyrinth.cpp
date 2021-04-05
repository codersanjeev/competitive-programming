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

vector<pair<int, int>> delta = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
vector<char> dir = {'L', 'R', 'D', 'U'};

void solve(int tc) {
    int n, m;
    read(n, m);
    vector<string> arr(n);
    pair<int, int> start, end;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<int>> prev(n, vector<int>(m));
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        read(arr[i]);
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 'A') {
                start.first = i;
                start.second = j;
            }
            if (arr[i][j] == 'B') {
                end.first = i;
                end.second = j;
            }
        }
    }
    q.push(start);
    visited[start.first][start.second] = true;
    while (!q.empty()) {
        auto curr = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int x = curr.first + delta[i].first;
            int y = curr.second + delta[i].second;
            if (x >= 0 && x < n && y >= 0 && y < m && !visited[x][y] && arr[x][y] != '#') {
                visited[x][y] = true;
                q.push({x, y});
                prev[x][y] = i;
            }
        }
    }
    if (visited[end.first][end.second]) {
        write("YES\n");
        vector<int> ans;
        while (end != start) {
            int x = prev[end.first][end.second];
            ans.push_back(x);
            end = {end.first - delta[x].first, end.second - delta[x].second};
        }
        reverse(ans.begin(), ans.end());
        write(ans.size(), "\n");
        for (const auto &ele : ans) {
            write(dir[ele]);
        }
    } else {
        write("NO");
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
