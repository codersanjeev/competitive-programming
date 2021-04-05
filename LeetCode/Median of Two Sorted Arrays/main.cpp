class Solution {
  public:
	double findMedianSortedArrays(vector<int> &A, vector<int> &B) {
		int x = A.size(), y = B.size();
		if (x > y) {
			return findMedianSortedArrays(B, A);
		}
		int lo = 0, hi = x;
		while (lo <= hi) {
			int px = lo + (hi - lo) / 2;
			int py = (x + y + 1) / 2;
			py -= px;
			int maxLeftX = (px == 0 ? INT_MIN : A[px - 1]);
			int minRightX = (px == x ? INT_MAX : A[px]);
			int maxLeftY = (py == 0 ? INT_MIN : B[py - 1]);
			int minRightY = (py == y ? INT_MAX : B[py]);
			if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
				if ((x + y) % 2 == 0) {
					return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) * 1.0 * 0.5;
				} else {
					return max(maxLeftX, maxLeftY) * 1.0;
				}
			} else if (maxLeftX > minRightY) {
				hi = px - 1;
			} else {
				lo = px + 1;
			}
		}
		return 0.0;
	}
};