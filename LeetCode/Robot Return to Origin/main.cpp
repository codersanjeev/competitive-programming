class Solution {
  public:
	bool judgeCircle(string moves) {
		int up = 0, left = 0;
		for (const auto &ch : moves) {
			if (ch == 'U') {
				up++;
			} else if (ch == 'D') {
				up--;
			} else if (ch == 'L') {
				left++;
			} else {
				left--;
			}
		}
		return up == 0 && left == 0;
	}
};