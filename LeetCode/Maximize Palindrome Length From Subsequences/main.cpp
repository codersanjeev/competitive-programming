#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int longestPalindrome(const string &A, const string &B) {
        int N = A.size(), M = B.size();
        string S = A + B;
        int ans = 0;
        memset(dp, sizeof(dp), 0);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (A[i] == B[j]) {
                    ans = max(ans, longestPalindromeUtility(i, N + j, N, S));
                }
            }
        }
        return ans;
    }

   private:
    int dp[2002][2002];

    int longestPalindromeUtility(int i, int j, int N, const string &S) {
        if (i >= j) {
            return i == j;
        }
        if (dp[i][j] != 0) {
            return dp[i][j];
        }
        if (S[i] == S[j]) {
            return dp[i][j] = 2 + longestPalindromeUtility(i + 1, j - 1, N, S);
        } else {
            return dp[i][j] = max(longestPalindromeUtility(i + 1, j, N, S), longestPalindromeUtility(i, j - 1, N, S));
        }
    }
};