#include <bits/stdc++.h>
using namespace std;

int findShortestPath(pair<int, int> x, pair<int, int> y) {
    if (x.first == y.first && x.second == y.second) return 0;
    vector<int> dx = {2, 2, -2, -2, 1, 1, -1, -1};
    vector<int> dy = {-1, 1, 1, -1, 2, -2, 2, -2};
    int n = 8;
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    vector<vector<int>> dist(n, vector<int>(n, 0));
    queue<pair<int, int>> q;
    q.push(x);
    visited[x.first][x.second] = true;
    while (!q.empty()) {
        auto curr = q.front();
        q.pop();
        if (curr.first == y.first && curr.second == y.second) {
            return dist[curr.first][curr.second];
        }
        for (int i = 0; i < n; i++) {
            int nx = curr.first + dx[i];
            int ny = curr.second + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny]) {
                visited[nx][ny] = true;
                dist[nx][ny] = dist[curr.first][curr.second] + 1;
                q.push({nx, ny});
            }
        }
    }
    return 0;
}

int main() {
    int t;
    string a, b;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        pair<int, int> src = {-1, -1};
        pair<int, int> dest = {-1, -1};
        src.first = 8 - (a[1] - '0');
        src.second = a[0] - 'a';
        dest.first = 8 - (b[1] - '0');
        dest.second = b[0] - 'a';
        cout << findShortestPath(src, dest) << "\n";
    }
    return 0;
}