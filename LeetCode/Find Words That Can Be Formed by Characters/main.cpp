class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
		int ans = 0;
		vector<int> freq(26, 0);
		for (const auto &ch : chars) {
			freq[ch - 'a']++;
		}
		for (const auto &word : words) {
			vector<int> cnt(26, 0);
			for (const auto &ch : word) {
				cnt[ch - 'a']++;
			}
			bool good = true;
			for (int i = 0; i < 26; i++) {
				if (cnt[i] > freq[i]) {
					good = false;
					break;
				}
			}
			if (good) {
				ans += word.size();
			}
		}
		return ans;        
    }
};