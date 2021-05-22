class Solution {
   private:
    vector<vector<string>> ans;

    bool isSafe(const vector<string> &board, int row, int col, int n) {
        for (int i = 0; i < row; ++i) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }
        int i = row - 1, j = col - 1;
        while (i >= 0 && j >= 0) {
            if (board[i][j] == 'Q') return false;
            --i;
            --j;
        }
        i = row - 1, j = col + 1;
        while (i >= 0 && j < n) {
            if (board[i][j] == 'Q') return false;
            --i;
            ++j;
        }
        return true;
    }

    void solve(vector<string> &board, int row, int n) {
        if (row == n) {
            ans.push_back(board);
            return;
        }
        for (int col = 0; col < n; ++col) {
            if (isSafe(board, row, col, n)) {
                board[row][col] = 'Q';
                solve(board, row + 1, n);
                board[row][col] = '.';
            }
        }
    }

   public:
    int totalNQueens(int n) {
        string s(n, '.');
        vector<string> board(n, s);
        solve(board, 0, n);
        return ans.size();
    }
};