class Solution {
   public:
    vector<int> arraysIntersection(vector<int>& A, vector<int>& B, vector<int>& C) {
        vector<int> ans;
        int x = A.size(), y = B.size(), z = C.size(), i = 0, j = 0, k = 0;
        while (i < x && j < y && k < z) {
            int mn = min({A[i], B[j], C[k]});
            if (A[i] == B[j] && B[j] == C[k]) {
                ans.push_back(A[i]);
                i++;
                j++;
                k++;
            } else if (A[i] == mn) {
                i++;
            } else if (B[j] == mn) {
                j++;
            } else {
                k++;
            }
        }
        return ans;
    }
};