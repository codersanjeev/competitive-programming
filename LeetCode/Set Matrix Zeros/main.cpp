class Solution {
   public:
    void makeColumnZero(vector<vector<int>> &matrix, int j, int n) {
        for (int i = 0; i < n; i++) {
            matrix[i][j] = 0;
        }
    }

    void makeRowZero(vector<vector<int>> &matrix, int i, int m) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = 0;
        }
    }

    void setZeroes(vector<vector<int>> &matrix) {
        int n = matrix.size(), m = matrix[0].size();
        bool rowHasZero = false, columnHasZero = false;

        for (int j = 0; j < m; j++) {
            if (matrix[0][j] == 0) {
                rowHasZero = true;
                break;
            }
        }

        for (int i = 0; i < n; i++) {
            if (matrix[i][0] == 0) {
                columnHasZero = true;
                break;
            }
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        for (int i = 1; i < n; i++) {
            if (matrix[i][0] == 0) {
                makeRowZero(matrix, i, m);
            }
        }

        for (int j = 1; j < m; j++) {
            if (matrix[0][j] == 0) {
                makeColumnZero(matrix, j, n);
            }
        }

        if (rowHasZero) {
            makeRowZero(matrix, 0, m);
        }

        if (columnHasZero) {
            makeColumnZero(matrix, 0, n);
        }
    }
};