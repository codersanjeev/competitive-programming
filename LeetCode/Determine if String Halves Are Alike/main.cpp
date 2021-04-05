class Solution {
  public:

	set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

	bool halvesAreAlike(string s) {
		int n = s.size(), cnt = 0;
		for (int i = 0; i < n / 2; i++) {
			if (vowels.count(s[i]) == 0) {
				continue;
			}
			cnt++;
		}
		for (int i = n / 2; i < n; i++) {
			if (vowels.count(s[i]) == 0) {
				continue;
			}
			if (cnt == 0) {
				return false;
			}
			cnt--;
		}
		return cnt == 0;
	}
};