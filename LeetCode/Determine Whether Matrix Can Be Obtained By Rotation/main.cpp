class Solution {
   public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for (int i = 0; i < 4; ++i) {
            if (mat == target) return true;
            rotate(mat);
        }
        return false;
    }

    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (auto& row : matrix) {
            reverse(row.begin(), row.end());
        }
    }
};