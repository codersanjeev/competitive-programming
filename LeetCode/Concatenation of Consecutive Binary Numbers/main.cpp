class Solution {
  public:
	int concatenatedBinary(int n) {
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			int len = toBinary(i);
			ans = ((ans * (1LL << len)) + i) % mod;
		}
		return ans;
	}

  private:

	const int mod = 1e9 + 7;

	int toBinary(int n) {
		int ans = 0;
		while (n > 0) {
			ans++;
			n >>= 1;
		}
		return ans;
	}
};