class Solution {
  public:
	bool closeStrings(string word1, string word2) {
		vector<int>w1(26, 0), w2(26, 0), w3(26, 0), w4(26, 0);
		for (const auto &c : word1) {
			w1[c - 'a']++, w3[c - 'a'] = 1;
		}
		for (const auto &c : word2) {
			w2[c - 'a']++, w4[c - 'a'] = 1;
		}
		sort(begin(w1), end(w1));
		sort(begin(w2), end(w2));
		return w1 == w2 && w3 == w4;
	}
};