class Solution {
  public:
	int thirdMax(vector<int>& nums) {
		set<int> st(nums.begin(), nums.end());
		auto it = st.end();
		it--;
		if (st.size() < 3) {
			return *it;
		}
		it--;
		it--;
		return *it;
	}
};