class Solution {
  public:
	int maxSumTwoNoOverlap(vector<int> &A, int L, int M) {
		// lMax -> [L, M]
		// rMax -> [M, L]
		int N = A.size();
		for (int i = 1; i < N; i++) {
			A[i] += A[i - 1];
		}
		int ans = A[L + M - 1], lMax = A[L - 1], mMax = A[M - 1];
		for (int i = L + M; i < N; i++) {
			lMax = max(lMax, A[i - M] - A[i - (L + M)]);
			mMax = max(mMax, A[i - L] - A[i - (L + M)]);
			ans = max({ans, lMax + A[i] - A[i - M], mMax + A[i] - A[i - L]});
		}
		return ans;
	}
};