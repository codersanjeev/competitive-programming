class Solution {
  public:
	int longestSubstring(string s, int k) {
		vector<int> freq(26, 0);
		for (const auto &ele : s) {
			freq[ele - 'a']++;
		}
		for (int i = 0; i < s.size(); i++) {
			if (freq[s[i] - 'a'] >= k) {
				continue;
			}
			int j = i + 1;
			while (j < s.size() && freq[s[j] - 'a'] < k) {
				j++;
			}
			return max(longestSubstring(s.substr(0, i), k), longestSubstring(s.substr(j), k));
		}
		return s.size();
	}
};