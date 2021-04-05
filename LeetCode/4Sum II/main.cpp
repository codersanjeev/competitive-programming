class Solution {
  public:
	int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D) {
		unordered_map<int, int> mpa, mpb;
		int n = A.size();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				mpa[A[i] + B[j]]++;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				mpb[C[i] + D[j]]++;
			}
		}
		int ans = 0;
		for (const auto &ele : mpa) {
			if (mpb.find(ele.first * -1) != mpb.end()) {
				ans += (ele.second * mpb[ele.first * -1]);
			}
		}
		return ans;
	}
};