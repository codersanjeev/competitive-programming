class Solution {
  public:
	vector<vector<int> > updateMatrix(vector<vector<int> > &matrix) {
		int rows = matrix.size();
		if (rows == 0) {
			return matrix;
		}
		int cols = matrix[0].size();
		vector<vector<int> > dist(rows, vector<int>(cols, INT_MAX - 100000));
		//First pass: check for left and top
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (matrix[i][j] == 0) {
					dist[i][j] = 0;
				} else {
					if (i > 0) {
						dist[i][j] = min(dist[i][j], dist[i - 1][j] + 1);
					}
					if (j > 0) {
						dist[i][j] = min(dist[i][j], dist[i][j - 1] + 1);
					}
				}
			}
		}
		//Second pass: check for bottom and right
		for (int i = rows - 1; i >= 0; i--) {
			for (int j = cols - 1; j >= 0; j--) {
				if (i < rows - 1) {
					dist[i][j] = min(dist[i][j], dist[i + 1][j] + 1);
				}
				if (j < cols - 1) {
					dist[i][j] = min(dist[i][j], dist[i][j + 1] + 1);
				}
			}
		}
		return dist;
	}
};