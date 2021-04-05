class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int x = 0, y = 0, ans = 0;
        for (int i = 0; i < 8; i++) {
        	for (int j = 0; j < 8; j++) {
        		if (board[i][j] == 'R') {
        			x = i;
        			y = j;
        		}
        	}
        }
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {-1, 1, 0, 0};
        for (int k = 0; k < 4; k++) {
        	int i = x, j = y;
        	while (isSafe(i, j)) {
        		if (board[i][j] == 'p') {
        			ans++;
        			break;
        		}
        		if (board[i][j] != '.' && board[i][j] != 'R') {
        			break;
        		}
        		i += dx[k];
        		j += dy[k];
        	}
        }
        return ans;
    }
private:
	bool isSafe(int x, int y) {
		return x >= 0 && y >= 0 && x < 8 && y < 8;
	}
};