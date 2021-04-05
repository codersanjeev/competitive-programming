class Solution {
  public:
	vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
		int n = mat.size(), m = mat[0].size();
		for (int i = 0; i < n; i++) {
			int x = i, y = 0;
			vector<int> temp;
			while (x >= 0 && y >= 0 && x < n && y < m) {
				temp.push_back(mat[x][y]);
				x++;
				y++;
			}
			sort(temp.begin(), temp.end());
			x = i, y = 0;
			int k = 0;
			while (x >= 0 && y >= 0 && x < n && y < m) {
				mat[x][y] = temp[k++];
				x++;
				y++;
			}
		}
		for (int j = 0; j < m; j++) {
			int x = 0, y = j;
			vector<int> temp;
			while (x >= 0 && y >= 0 && x < n && y < m) {
				temp.push_back(mat[x][y]);
				x++;
				y++;
			}
			sort(temp.begin(), temp.end());
			x = 0, y = j;
			int k = 0;
			while (x >= 0 && y >= 0 && x < n && y < m) {
				mat[x][y] = temp[k++];
				x++;
				y++;
			}
		}
		return mat;
	}
};