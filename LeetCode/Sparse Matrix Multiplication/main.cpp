class Solution {
   public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n = A.size();
        int m = B[0].size();
        vector<vector<int>> ans(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[i][j] = 0;
                for (int k = 0; k < A[0].size(); k++) {
                    ans[i][j] += (A[i][k] * B[k][j]);
                }
            }
        }
        return ans;
    }
};