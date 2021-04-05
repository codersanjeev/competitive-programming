class Solution {
  public:

	bool isValid(const char &ch) {
		if (ch >= 'a' && ch <= 'z') {
			return true;
		}
		if (ch >= 'A' && ch <= 'Z') {
			return true;
		}
		if (ch >= '0' && ch <= '9') {
			return true;
		}
		return false;
	}

	bool isPalindrome(string s) {
		string t = "";
		for (const auto &ele : s) {
			if (isValid(ele)) {
				t += (char) tolower(ele);
			}
		}
		int n = t.size(), i = 0, j = n - 1;
		while (i < j) {
			if (t[i] != t[j]) {
				return false;
			}
			i++;
			j--;
		}
		return true;
	}
};