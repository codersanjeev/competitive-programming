#include <bits/stdc++.h>
using namespace std;

int solve(const string S) {
    if (S.empty()) return 0;
    int N = S.size();
    vector<vector<int>> DP(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) DP[i][i] = 1;
    for (int len = 2; len <= N; len++) {
        for (int i = 0; i < N - len + 1; i++) {
            int j = i + len - 1;
            if (S[i] == S[j] && len == 2) {
                DP[i][j] = 2;
            } else if (S[i] == S[j]) {
                DP[i][j] = DP[i + 1][j - 1] + 2;
            } else {
                DP[i][j] = max(DP[i + 1][j], DP[i][j - 1]);
            }
        }
    }
    return DP[0][N - 1];
}