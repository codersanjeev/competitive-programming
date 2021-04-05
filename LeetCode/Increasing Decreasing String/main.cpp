class Solution {
  public:
	string sortString(string s) {
		int n = s.size();
		vector<int> freq(26, 0);
		for (int i = 0; i < n; i++) {
			freq[s[i] - 'a']++;
		}
		string ans = "";
		while (ans.size() != n) {
			for (int i = 0; i < 26; i++) {
				if (freq[i] > 0) {
					ans += (char)(i + 'a');
					freq[i]--;
				}
			}
			for (int i = 25; i >= 0; i--) {
				if (freq[i] > 0) {
					ans += (char)(i + 'a');
					freq[i]--;
				}
			}
		}
		return ans;
	}
};