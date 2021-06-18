#include <bits/stdc++.h>
using namespace std;

vector<int> dx = {-1, -1, -1, 0, 1, 1, 1, 0};
vector<int> dy = {-1, 0, 1, 1, 1, 0, -1, -1};

int dfs(vector<vector<int>> &board, int i, int j) {
    if (i < 0 || j < 0 || i >= (int)board.size() || j >= (int)board[0].size()) {
        return 0;
    }
    if (board[i][j] == 0) {
        return 0;
    }
    int ans = board[i][j]--;
    for (int k = 0; k < 8; k++) {
        ans += dfs(board, i + dx[k], j + dy[k]);
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> board(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans = max(ans, dfs(board, i, j));
        }
    }
    cout << ans;
    return 0;
}