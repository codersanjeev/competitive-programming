class Solution {
   public:
    int snakesAndLadders(vector<vector<int>>& board) {
        vector<int> arr = convertToOneDimension(board);
        int n = arr.size();
        vector<bool> visited(n, false);
        queue<pair<int, int>> q;
        q.push({0, 0});
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            int u = curr.first;
            int d = curr.second;
            if (u == n - 1) {
                return d;
            }
            visited[u] = true;
            for (int i = 1; i <= 6; i++) {
                int ni = u + i;
                if (ni < n && arr[ni] != -1) {
                    ni = arr[ni] - 1;
                }
                if (ni >= n) {
                    continue;
                }
                if (ni == n - 1 || visited[ni] == false) {
                    q.push({ni, d + 1});
                }
            }
        }
        return -1;
    }

   private:
    vector<int> convertToOneDimension(const vector<vector<int>>& board) {
        int n = board.size();
        vector<int> ans;
        bool lr = true;
        for (int i = n - 1; i >= 0; i--) {
            if (lr) {
                for (int j = 0; j < n; j++) {
                    ans.push_back(board[i][j]);
                }
            } else {
                for (int j = n - 1; j >= 0; j--) {
                    ans.push_back(board[i][j]);
                }
            }
            lr = !lr;
        }
        return ans;
    }
};