auto speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int lo = 0, hi = numbers.size() - 1;
        while (lo < hi) {
        	int curr = numbers[lo] + numbers[hi];
        	if (curr == target) {
        		return {lo + 1, hi + 1};
        	} else if (curr > target) {
        		hi--;
        	} else {
        		lo++;
        	}
        }
        return {};
    }
};