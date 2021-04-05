#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> cheapestJump(vector<int> &A, int B) {
        long long N = A.size();
        vector<long long> next(N, -1);
        vector<long long> dp(N, -1);
        jump(A, B, 0, N, next, dp);
        vector<int> ans;
        long long i = 0;
        while (i < N && next[i] > 0) {
            ans.push_back(i + 1);
            i = next[i];
        }
        if (i == N - 1 && A[i] != -1) {
            ans.push_back(i + 1);
        } else {
            return {};
        }
        return ans;
    }

   private:
    long long jump(const vector<int> &A, long long B, long long idx, long long N, vector<long long> &next, vector<long long> &dp) {
        if (idx == N - 1 && A[idx] != -1) {
            return A[idx];
        }
        if (dp[idx] != -1) {
            return dp[idx];
        }
        long long ans = INT_MAX;
        for (long long k = 1; k <= B; k++) {
            long long j = idx + k;
            if (j < N && A[j] != -1) {
                long long cost = A[idx] + jump(A, B, j, N, next, dp);
                if (cost < ans) {
                    ans = cost;
                    next[idx] = j;
                }
            }
        }
        dp[idx] = ans;
        return ans;
    }
};