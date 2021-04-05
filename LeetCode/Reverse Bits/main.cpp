class Solution {
  public:
	uint32_t reverseBits(uint32_t n) {
		uint32_t ans = 0, p = 31;
		while (n > 0) {
			if (n & 1) {
				ans += (1 << p);
			}
			n >>= 1;
			p--;
		}
		return ans;
	}
};