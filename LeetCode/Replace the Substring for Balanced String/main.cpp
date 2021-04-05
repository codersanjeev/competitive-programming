class Solution {
  public:

	int charToInt(const char &ch) {
		int ans = -1;
		if (ch == 'Q') {
			ans = 0;
		} else if (ch == 'W') {
			ans = 1;
		} else if (ch == 'E') {
			ans = 2;
		} else {
			ans = 3;
		}
		return ans;
	}

	int balancedString(string s) {
		// QWER
		vector<int> freq(4);
		for (const auto &ele : s) {
			freq[charToInt(ele)]++;
		}
		int i = 0, j = 0, ans = s.size(), mn = ans / 4, n = ans;
		while (i < n) {
			freq[charToInt(s[i])]--;
			while (freq[charToInt('Q')] <= mn && freq[charToInt('W')] <= mn && freq[charToInt('E')] <= mn && freq[charToInt('R')] <= mn) {
				freq[charToInt(s[j])]++;
				ans = min(ans, i - j + 1);
				j++;
				if (j == n) {
					break;
				}
			}
			i++;
		}
		return ans;
	}
};