class Solution {
  public:
	vector<int> spiralOrder(vector<vector<int>> &matrix) {
		int n = matrix.size(), m = matrix[0].size(), top = 0, left = 0, bottom = n - 1, right = m - 1, dir = 0;
		vector<int> ans;
		while (top <= bottom && left <= right) {
			if (dir == 0) {
				// left --> right
				for (int j = left; j <= right; j++) {
					ans.push_back(matrix[top][j]);
				}
				top++;
			} else if (dir == 1) {
				// top --> bottom
				for (int i = top; i <= bottom; i++) {
					ans.push_back(matrix[i][right]);
				}
				right--;
			} else if (dir == 2) {
				// right --> left
				for (int j = right; j >= left; j--) {
					ans.push_back(matrix[bottom][j]);
				}
				bottom--;
			} else {
				// bottom --> top
				for (int i = bottom; i >= top; i--) {
					ans.push_back(matrix[i][left]);
				}
				left++;
			}
			dir = (dir + 1) % 4;
		}
		return ans;
	}
};