auto speedup = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return nullptr;
}();

class Solution {
  public:
	vector<int> plusOne(vector<int>& digits) {
		vector<int> ans;
		int carry = 1, j = digits.size() - 1;
		while (j >= 0) {
			int curr = digits[j--] + carry;
			ans.push_back(curr % 10);
			carry = curr / 10;
		}
		if (carry > 0) ans.push_back(carry);
		reverse(ans.begin(), ans.end());
		return ans;
	}
};