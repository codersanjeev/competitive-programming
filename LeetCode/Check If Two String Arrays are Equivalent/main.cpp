class Solution {
  public:
	bool arrayStringsAreEqual(vector<string> &A, vector<string> &B) {
		string x = "", y = "";
		for (const auto &ele : A) {
			x += ele;
		}
		for (const auto &ele : B) {
			y += ele;
		}
		return x == y;
	}
};