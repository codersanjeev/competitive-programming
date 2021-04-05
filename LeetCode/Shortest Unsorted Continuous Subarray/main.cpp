#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int findUnsortedSubarray(vector<int>& A) {
        int N = A.size(), i = 0, j = N - 1;
        while (i < N) {
            if (i + 1 < N && A[i] > A[i + 1]) {
                break;
            } else {
                i++;
            }
        }
        while (j >= 0) {
            if (j - 1 >= 0 && A[j - 1] > A[j]) {
                break;
            } else {
                j--;
            }
        }
        if (i > j) return 0;
        int mx = INT_MIN, mn = INT_MAX;
        for (int k = i; k <= j; k++) {
            mx = max(mx, A[k]);
            mn = min(mn, A[k]);
        }
        for (int k = 0; k < i; k++) {
            if (A[k] > mn) {
                i = k;
                break;
            }
        }
        for (int k = N - 1; k > j; k--) {
            if (A[k] < mx) {
                j = k;
                break;
            }
        }
        return j - i + 1;
    }
};