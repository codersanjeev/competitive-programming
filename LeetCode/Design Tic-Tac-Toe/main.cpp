class TicTacToe {
   public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        this->n = n;
        this->board.resize(n, vector<int>(n, 0));
    }

    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        board[row][col] = player;
        if (isWinning(1, row, col)) {
            return 1;
        } else if (isWinning(2, row, col)) {
            return 2;
        } else {
            return 0;
        }
    }

   private:
    int n;
    vector<vector<int>> board;

    bool isWinning(int player, int row, int col) {
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (board[i][i] != player) {
                ok = false;
            }
        }
        if (ok) {
            return ok;
        }
        ok = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if ((i + j) == n - 1 && board[i][j] != player) {
                    ok = false;
                }
            }
        }
        if (ok) {
            return ok;
        }
        ok = true;
        for (int j = 0; j < n; j++) {
            if (board[row][j] != player) {
                ok = false;
            }
        }
        if (ok) {
            return ok;
        }
        ok = true;
        for (int i = 0; i < n; i++) {
            if (board[i][col] != player) {
                ok = false;
            }
        }
        if (ok) {
            return ok;
        }
        return false;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */