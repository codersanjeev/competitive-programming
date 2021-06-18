#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> arr(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                arr[i][j] = matrix[i - 1][j - 1];
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 2; j <= m; ++j) {
                arr[i][j] += arr[i][j - 1];
            }
        }
        for (int j = 1; j <= m; ++j) {
            for (int i = 2; i <= n; ++i) {
                arr[i][j] += arr[i - 1][j];
            }
        }
        int ans = 0;
        for (int tli = 1; tli <= n; ++tli) {
            for (int tlj = 1; tlj <= m; ++tlj) {
                for (int bli = tli; bli <= n; ++bli) {
                    for (int blj = tlj; blj <= m; ++blj) {
                        int curr = arr[bli][blj] + arr[tli - 1][tlj - 1];
                        curr -= arr[bli][tlj - 1];
                        curr -= arr[tli - 1][blj];
                        if (curr == target) {
                            ++ans;
                        }
                    }
                }
            }
        }
        return ans;
    }
};