class Solution {
  public:
	string generateTheString(int n) {
		if (n % 2 == 0) {
			string ans(n - 1, 'a');
			return ans + "b";
		} else {
			string ans(n, 'a');
			return ans;
		}
	}
};