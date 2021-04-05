class Solution {
  public:
	int longestOnes(vector<int> &A, int K) {
		int n = A.size(), i = 0, j = 0;
		while (j < n) {
			if (A[j] == 0) {
				K--;
			}
			if (K < 0 && A[i++] == 0) {
				K++;
			}
			j++;
		}
		return j - i;
	}
};