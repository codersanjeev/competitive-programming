#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, m;
    vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
    vector<int> dy = {-1, 0, 1, -1, 1, -1, 0, 1};
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<vector<int>> ans(n, vector<int>(m, 0));
        auto safe = [&](int i, int j) {
            return i >= 0 && j >= 0 && i < n && j < m;
        };
        auto good = [&](int i, int j) {
            if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                for (int k = 0; k < 8; ++k) {
                    int x = i + dx[k], y = j + dy[k];
                    if (safe(x, y) && ans[x][y] == 1) return false;
                }
                return true;
            }
            return false;
        };
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (good(i, j)) ans[i][j] = 1;
                cout << ans[i][j];
            }
            cout << "\n";
        }
        cout << "\n";
    }
    return 0;
}