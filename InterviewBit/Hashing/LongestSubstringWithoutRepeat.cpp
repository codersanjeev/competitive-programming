int Solution::lengthOfLongestSubstring(string s) {
	int n = s.size();
	unordered_map<char, int> mp;
	int ans = 0;
	int j = 0;
	for (int i = 0; i < n; i++) {
		mp[s[i]]++;
		while (j < i && mp[s[i]] > 1) {
			mp[s[j]]--;
			j++;
		}
		ans = max(ans, i - j + 1);
	}
	return ans;
}
