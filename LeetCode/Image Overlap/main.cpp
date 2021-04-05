class Solution {
  public:
	int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
		int N = A.size(), ans = 0;
		for (int row = -N + 1; row < N; row++) {
			for (int col = -N + 1; col < N; col++) {
				ans = max(ans, solve(A, B, row, col, N));
			}
		}
		return ans;
	}

	int solve(const vector<vector<int>> &A, const vector<vector<int>> &B, int rowOff, int colOff, int N) {
		int ans = 0;
		for (int row = 0; row < N; row++) {
			for (int col = 0; col < N; col++) {
				int nr = row + rowOff;
				int nc = col + colOff;
				if (nr < 0 || nc < 0 || nr >= N || nc >= N) {
					continue;
				}
				if (A[row][col] + B[nr][nc] == 2) {
					ans++;
				}
			}
		}
		return ans;
	}

};