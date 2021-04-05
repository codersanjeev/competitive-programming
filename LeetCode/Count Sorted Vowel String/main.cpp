class Solution {
  public:
	int countVowelStrings(int n) {
		int ans = 1;
		for (int i = 1; i <= 4; i++) {
			ans *= (n + i);
		}
		return ans / 24;
	}
};