#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& A, vector<int>& B) {
    int N = A.size(), M = B.size(), ans = -1;
    if (N > M) {
        return solve(B, A);
    }
    int lo = 0, hi = N;
    while (lo <= hi) {
        int midOnA = lo + (hi - lo) / 2;
        int midOnB = (N + M + 1) / 2 - midOnA;

        int minOnA = midOnA == N ? INT_MAX : A[midOnA];
        int maxOnA = midOnA == 0 ? INT_MIN : A[midOnA - 1];

        int minOnB = midOnB == M ? INT_MAX : B[midOnB];
        int maxOnB = midOnB == 0 ? INT_MIN : B[midOnB - 1];

        if (maxOnA <= minOnB && maxOnB <= minOnA) {
            if ((N + M) % 2 == 0) {
                ans = min(minOnA, minOnB);
            } else {
                ans = max(maxOnA, maxOnB);
            }
            break;
        } else if (maxOnA > minOnB) {
            hi = midOnA - 1;
        } else {
            lo = midOnA + 1;
        }
    }
    return ans;
}