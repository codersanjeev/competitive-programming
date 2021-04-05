class Solution {
  public:
	vector<vector<int>> intervalIntersection(vector<vector<int>> &A, vector<vector<int>> &B) {
		int n = A.size(), m = B.size(), i = 0, j = 0;
		vector<vector<int>> ans;
		while (i < n && j < m) {
			if (A[i][1] >= B[j][0] && A[i][0] <= B[j][1]) {
				ans.push_back({max(A[i][0], B[j][0]), min(A[i][1], B[j][1])});
			}
			if (A[i][1] < B[j][1]) {
				i++;
			} else {
				j++;
			}
		}
		return ans;
	}
};