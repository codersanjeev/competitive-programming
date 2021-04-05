auto speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int missingNumber(vector<int>& nums) {
    	int n = nums.size();
    	int available = accumulate(nums.begin(), nums.end(), 0);
		int total = ((n + 1) * n) / 2;
		return total - available;    	
    }
};