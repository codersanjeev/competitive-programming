class Solution {
  public:
	bool isAnagram(string s, string t) {
		vector<int> a(26, 0), b(26, 0);
		for (const auto &ele : s) {
			a[ele - 'a']++;
		}
		for (const auto &ele : t) {
			b[ele - 'a']++;
		}
		return a == b;
	}
};