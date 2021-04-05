#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size(), L = 0, R = (m * n) - 1;
        while (L != R) {
            int M = L + (R - L) / 2;
            if (matrix[M / m][M % m] < target) {
                L = M + 1;
            } else {
                R = M;
            }
        }
        return matrix[R / m][R % m] == target;
    }
};