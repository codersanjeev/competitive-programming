class Solution {
  public:
	int subarraysWithKDistinct(vector<int> &A, int K) {
		return f(A, K) - f(A, K - 1);
	}
  private:
	int f(const vector<int> &A, int K) {
		if (K == 0) {
			return 0;
		}
		int N = A.size(), i = 0, j = 0, ans = 0, curr = 0;
		map<int, int> mp;
		while (i < N) {
			if (mp[A[i]] == 0) {
				curr++;
				mp[A[i]]++;
			} else {
				mp[A[i]]++;
			}
			if (curr <= K) {
				ans += (i - j + 1);
			} else {
				while (j <= i && curr > K) {
					mp[A[j]]--;
					if (mp[A[j]] == 0) {
						curr--;
					}
					j++;
				}
				ans += (i - j + 1);
			}
			i++;
		}
		return ans;
	}
};