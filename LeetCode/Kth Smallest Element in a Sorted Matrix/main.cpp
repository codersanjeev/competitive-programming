#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), lo = matrix[0][0], hi = matrix[n - 1][n - 1], ans;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int cnt = numberOfElementsLessThanOrEqualTo(matrix, n, mid);
            if (cnt < k) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }

   private:
    int numberOfElementsLessThanOrEqualTo(const vector<vector<int>>& matrix, int n, int x) {
        int ans = 0;
        for (const auto& row : matrix) {
            ans += lower_bound(row.begin(), row.end(), x) - row.begin();
        }
        return ans;
    }
};