class Solution {
  public:
	bool checkIfExist(vector<int>& arr) {
		map<int, int> mp;
		for (const auto &ele : arr) {
			mp[ele]++;
		}
		for (const auto &ele : arr) {
			if (ele == 0 && mp[ele] > 1) {
				return true;
			}
			if (ele != 0 && mp[ele * 2] > 0) {
				return true;
			}
		}
		return false;
	}
};