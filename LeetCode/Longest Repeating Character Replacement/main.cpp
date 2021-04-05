class Solution {
  public:
	int characterReplacement(string s, int k) {
		// ABAB , k = 2 => 4
		// AABABBA , k = 1 => 4
		int N = s.size(), i = 0, j = 0, ans = 0, curr = 0;
		vector<int> freq(26, 0);
		while (j < N) {
			freq[s[j] - 'A']++;
			curr = max(curr, freq[s[j] - 'A']);
			while (j - i - curr + 1 > k) {
				freq[s[i] - 'A']--;
				i++;
			}
			ans = max(ans, j - i + 1);
			j++;
		}
		return ans;
	}
};