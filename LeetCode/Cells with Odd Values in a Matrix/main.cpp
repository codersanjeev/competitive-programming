class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<vector<int>> arr(n, vector<int>(m, 0));
        for (const auto &xy : indices) {
            int x = xy[0];
            int y = xy[1];
            for (int j = 0; j < m; j++) {
                arr[x][j]++;
            }
            for (int i = 0; i < n; i++) {
                arr[i][y]++;
            }
        }
        int ans = 0;
        for (const auto &row : arr) {
            for (const auto &ele : row) {
                if (ele % 2 == 1) {
                    ans++;
                }
            }
        }
        return ans;
    }
};