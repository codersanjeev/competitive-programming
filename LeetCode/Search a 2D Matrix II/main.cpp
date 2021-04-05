#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size(), i = 0, j = m - 1;
        while (i < n && j >= 0) {
            int curr = matrix[i][j];
            if (curr == target) {
                return true;
            } else if (curr > target) {
                j--;
            } else {
                i++;
            }
        }
        return false;
    }
};