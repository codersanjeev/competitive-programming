vector<vector<int>> Solution::generateMatrix(int n) {
	vector<vector<int>> ans(n, vector<int>(n));
	int direction = 0;
	int top = 0, left = 0, bottom = n - 1, right = n - 1;
	int curr = 1;
	while (top <= bottom && left <= right) {
		switch (direction) {
		case 0 :
			for (int j = left; j <= right; j++) {
				ans[top][j] = curr;
				curr++;
			}
			top++;
			direction = 1;
			break;
		case 1 :
			for (int i = top; i <= bottom; i++) {
				ans[i][right] = curr;
				curr++;
			}
			right--;
			direction = 2;
			break;
		case 2 :
			for (int j = right; j >= left; j--) {
				ans[bottom][j] = curr;
				curr++;
			}
			bottom--;
			direction = 3;
			break;
		case 3 :
			for (int i = bottom; i >= top; i--) {
				ans[i][left] = curr;
				curr++;
			}
			left++;
			direction = 0;
			break;
		}
	}
	return ans;
}