class Solution {
  public:
	string maximumTime(string s) {
		if (s[0] == '?' && s[1] == '?') {
			s[0] = '2';
			s[1] = '3';
		} else if (s[0] == '?') {
			if (s[1] < '4') {
				s[0] = '2';
			} else {
				s[0] = '1';
			}
		} else if (s[1] == '?') {
			if (s[0] == '2') {
				s[1] = '3';
			} else {
				s[1] = '9';
			}
		}
		if (s[3] == '?' && s[4] == '?') {
			s[3] = '5';
			s[4] = '9';
		} else if (s[3] == '?') {
			s[3] = '5';
		} else if (s[4] == '?') {
			s[4] = '9';
		}
		return s;
	}
};