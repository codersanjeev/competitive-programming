class Solution {
   public:
    int wiggleMaxLength(vector<int>& A) {
        int N = A.size(), X = 1, Y = 1;
        for (int i = 1; i < N; i++) {
            if (A[i] > A[i - 1]) {
                X = Y + 1;
            } else if (A[i] < A[i - 1]) {
                Y = X + 1;
            }
        }
        return max(X, Y);
    }
};