auto speedup = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return nullptr;
}();

class Solution {
  public:
	vector<int> addToArrayForm(vector<int>& A, int K) {
		vector<int> ans;
		int j = A.size() - 1, carry = 0;
		while (K > 0 && j >= 0) {
			int curr = A[j--] + carry + K % 10;
			ans.push_back(curr % 10);
			carry = curr / 10;
			K /= 10;
		}
		while (j >= 0) {
			int curr = A[j--] + carry;
			ans.push_back(curr % 10);
			carry = curr / 10;
		}
		while (K > 0) {
			int curr = K % 10 + carry;
			ans.push_back(curr % 10);
			carry = curr / 10;
			K /= 10;
		}
		if (carry > 0) ans.push_back(carry);
		reverse(ans.begin(), ans.end());
		return ans;
	}
};