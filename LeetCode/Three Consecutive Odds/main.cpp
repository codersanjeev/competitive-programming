class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        for (auto &ele : arr) {
        	ele %= 2;
        }
        for (int i = 1; i < arr.size(); i++) {
        	if (arr[i] == 1) {
        		arr[i] += arr[i - 1];
        	}
        }
        for (const auto &ele : arr) {
        	if (ele >= 3) {
        		return true;
        	}
        }
        return false;
    }
};