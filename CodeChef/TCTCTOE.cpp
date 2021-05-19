#include <bits/stdc++.h>
using namespace std;

map<vector<string>, int> states;

bool isWonOrDrawn(const vector<string> &state) {
    int emptyCount = 0;
    for (int i = 0; i < 3; ++i) {
        if (state[i][0] == state[i][1] && state[i][1] == state[i][2] &&
            (state[i][0] == 'O' || state[i][0] == 'X')) {
            return true;
        }
        if (state[0][i] == state[1][i] && state[1][i] == state[2][i] &&
            (state[0][i] == 'O' || state[0][i] == 'X')) {
            return true;
        }
    }
    if (state[0][0] == state[1][1] && state[1][1] == state[2][2] &&
        (state[0][0] == 'O' || state[0][0] == 'X')) {
        return true;
    }
    if (state[0][2] == state[1][1] && state[1][1] == state[2][0] &&
        (state[0][2] == 'O' || state[0][2] == 'X')) {
        return true;
    }
    for (const auto &row : state) {
        for (const auto &ele : row) {
            if (ele == '_') emptyCount++;
        }
    }
    return emptyCount == 0;
}

void precomputation(vector<string> &board, bool turn) {
    if (isWonOrDrawn(board)) {
        states[board] = 1;
        return;
    }
    states[board] = 2;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == '_') {
                board[i][j] = turn ? 'X' : 'O';
                precomputation(board, !turn);
                board[i][j] = '_';
            }
        }
    }
}

int main() {
    vector<string> board(3);
    board[0] = board[1] = board[2] = "___";
    precomputation(board, true);
    int T;
    cin >> T;
    while (T--) {
        for (auto &ele : board) cin >> ele;
        int ans = states[board];
        if (ans == 0) ans = 3;
        cout << ans << "\n";
    }
    return 0;
}
