class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j || i + j + 1 == n) {
                    ans += mat[i][j];
                }
            }
        }
        return ans;
    }
};