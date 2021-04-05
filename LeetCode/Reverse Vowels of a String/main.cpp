class Solution {
  public:

	bool isVowel(const char &ch) {
		string s = "aeiouAEIOU";
		for (const auto &ele : s) {
			if (ch == ele) {
				return true;
			}
		}
		return false;
	}

	string reverseVowels(string s) {
		int n = s.size(), i = 0, j = n - 1;
		while (i < j) {
			while (i < j && !isVowel(s[i])) {
				i++;
			}
			while (i < j && !isVowel(s[j])) {
				j--;
			}
			swap(s[i], s[j]);
			i++;
			j--;
		}
		return s;
	}
};