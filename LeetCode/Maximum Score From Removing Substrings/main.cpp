class Solution {
  public:
	int maximumGain(string s, int x, int y) {
		string ab = "ab", ba = "ba";
		if (y > x) {
			swap(x, y);
			swap(ab, ba);
		}
		// first remove all ab
		int ans = 0;
		string curr = "";
		for (const auto &ele : s) {
			if (!curr.empty() && ele == ab[1] && curr.back() == ab[0]) {
				ans += x;
				curr.pop_back();
			} else {
				curr.push_back(ele);
			}
		}
		// now, remove all ba
		s = curr;
		curr = "";
		for (const auto &ele : s) {
			if (!curr.empty() && ele == ba[1] && curr.back() == ba[0]) {
				ans += y;
				curr.pop_back();
			} else {
				curr.push_back(ele);
			}
		}
		return ans;
	}
};