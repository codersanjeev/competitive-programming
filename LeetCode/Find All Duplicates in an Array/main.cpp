class Solution {
  public:
	vector<int> findDuplicates(vector<int>& arr) {
		vector<int> ans;
		for (const auto &ele : arr) {
			if (arr[abs(ele) - 1] < 0) {
				ans.push_back(abs(ele));
			} else {
				arr[abs(ele) - 1] *= -1;
			}
		}
		return ans;
	}
};