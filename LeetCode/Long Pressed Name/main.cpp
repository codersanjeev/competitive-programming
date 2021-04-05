class Solution {
  public:
	bool isLongPressedName(string name, string typed) {
		int n = name.size(), m = typed.size(), i = 0, j = 0;
		while (j < m) {
			if (i < n && name[i] == typed[j]) {
				i++;
				j++;
			} else if (i > 0 && name[i - 1] == typed[j]) {
				j++;
			} else {
				return false;
			}
		}
		return i == n;
	}
};