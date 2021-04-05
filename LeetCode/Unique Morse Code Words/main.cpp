class Solution {
  public:

	vector<string> codes = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

	int uniqueMorseRepresentations(vector<string> &words) {
		set<string> ans;
		for (const auto &word : words) {
			string curr = "";
			for (const auto &ch : word) {
				curr += codes[ch - 'a'];
			}
			ans.insert(curr);
		}
		return ans.size();
	}
};