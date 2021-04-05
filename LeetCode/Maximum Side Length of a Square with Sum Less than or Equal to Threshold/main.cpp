#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool good(vector<vector<int>>& arr, int target, int len) {
        for (int i = len; i < arr.size(); i++) {
            for (int j = len; j < arr[0].size(); j++) {
                if (arr[i][j] - arr[i - len][j] - arr[i][j - len] + arr[i - len][j - len] <= target) {
                    return true;
                }
            }
        }
        return false;
    }

    int maxSideLength(vector<vector<int>>& A, int target) {
        int M = A.size(), N = A[0].size();
        vector<vector<int>> B(M + 1, vector<int>(N + 1, 0));
        for (int i = 1; i <= M; i++) {
            for (int j = 1; j <= N; j++) {
                B[i][j] = B[i - 1][j] + B[i][j - 1] - B[i - 1][j - 1] + A[i - 1][j - 1];
            }
        }
        int lo = 0, hi = min(M, N);
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (good(B, target, mid)) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return hi;
    }
};