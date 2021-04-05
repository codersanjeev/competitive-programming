class Solution {
  public:
	string getSmallestString(int n, int k) {
		string s = "";
		for (int i = n; i >= 1; i--) {
			int rem = k - i + 1;
			if (rem >= 26) {
				s += "z";
				k -= 26;
			} else {
				s += (char) (rem + 'a' - 1);
				k -= rem;
			}
		}
		reverse(s.begin(), s.end());
		return s;
	}
};