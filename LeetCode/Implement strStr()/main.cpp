class Solution {
  public:
	int strStr(string haystack, string needle) {
		if (needle.empty() || haystack == needle) {
			return 0;
		}
		if (needle.size() > haystack.size()) {
			return -1;
		}
		for (int i = 0; i < haystack.size() - needle.size() + 1; i++) {
			int j = 0;
			while (j < needle.size()) {
				if (needle[j] != haystack[i + j]) {
					break;
				}
				j++;
			}
			if (j == needle.size()) {
				return i;
			}
		}
		return -1;
	}
};