auto speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<char>> board(3, vector<char>(3, ' '));
        int curr = 0;
        for (const auto &move : moves) {
        	if (curr % 2 == 0) {
        		board[move[0]][move[1]] = 'X';
        	} else {
        		board[move[0]][move[1]] = 'O';
        	}
            curr++;
        	int res = checkGameStatus(board);
        	if (res == 1) {
        		return "A";
        	} else if (res == 2) {
        		return "B";
        	} else if (res == -1) {
        		return "Draw";
        	} else {
        		continue;
        	}
        }
        int res = checkGameStatus(board);
        if (res == 1) {
    		return "A";
    	} else if (res == 2) {
    		return "B";
    	} else if (res == -1) {
    		return "Draw";
    	} else {
    		return "Pending";
    	} 
    }

private:
	int checkGameStatus(const vector<vector<char>> &board) {
		if ((board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X') || (board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X') || (board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X') || (board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X') || (board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X') || (board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X') || (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') || (board[2][0] == 'X' && board[1][1] == 'X' && board[0][2] == 'X')) {
			return 1;
		}
		if ((board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O') || (board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O') || (board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O') || (board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O') || (board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O') || (board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O') || (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') || (board[2][0] == 'O' && board[1][1] == 'O' && board[0][2] == 'O')) {
			return 2;
		}
		int cnt = 0;
		for (const auto &row : board) {
			for (const auto &ele : row) {
				if (ele == ' ') cnt++;
			}
		}
		return (cnt > 0 ? 0 : -1);
	}
};