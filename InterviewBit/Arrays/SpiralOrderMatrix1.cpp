vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
	int m = A.size();
	int n = A[0].size();
	int top = 0, left = 0, bottom = m - 1, right = n - 1;
	int dir = 0;
	vector<int> ans;
	while (top <= bottom && left <= right) {
		if (dir == 0) {
			for (int j = left; j <= right; j++) {
				ans.push_back(A[top][j]);
			}
			top++;
			dir++;
		} else if (dir == 1) {
			for (int i = top; i <= bottom; i++) {
				ans.push_back(A[i][right]);
			}
			right--;
			dir++;
		} else if (dir == 2) {
			for (int j = right; j >= left; j--) {
				ans.push_back(A[bottom][j]);
			}
			bottom--;
			dir++;
		} else {
			for (int i = bottom; i >= top; i--) {
				ans.push_back(A[i][left]);
			}
			left++;
			dir = 0;
		}
	}
	return ans;
}