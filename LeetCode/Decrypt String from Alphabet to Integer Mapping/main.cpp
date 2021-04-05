class Solution {
  public:
	string freqAlphabets(string s) {
		map<string, char> mp;
		char ch = 'a';
		for (int i = 1; i <= 26; i++) {
			if (i >= 1 && i <= 9) {
				mp[to_string(i)] = ch;
			} else {
				mp[to_string(i) + "#"] = ch;
			}
			ch++;
		}
		string ans = "";
		int i = 0, n = s.size();
		while (i < n) {
			string x = s.substr(i, 3);
			if (mp.find(x) != mp.end()) {
				ans += mp[x];
				i += 3;
			} else {
				string curr(1, s[i]);
				ans += mp[curr];
				i++;
			}
		}
		return ans;
	}
};