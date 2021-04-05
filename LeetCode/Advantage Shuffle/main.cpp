#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        multiset<int> S(A.begin(), A.end());
        int i = 0;
        for (const auto& ele : B) {
            auto it = *S.rbegin() <= ele ? S.begin() : S.upper_bound(ele);
            A[i++] = *it;
            S.erase(it);
        }
        return A;
    }
};