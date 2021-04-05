class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        map<int, int> mp;
        for (const auto &ele : arr) {
        	mp[ele]++;
        }
        int n = arr.size(), reqd = n / 4;
        for (const auto &ele : mp) {
        	if (ele.second > reqd) {
        		return ele.first;
        	}
        }
        return -1;
    }
};