class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        int n = arr.size(), mn = INT_MAX;
        for (int i = 1; i < n; i++) {
        	mn = min(mn, arr[i] - arr[i - 1]);
        }
        for (int i = 1; i < n; i++) {
        	if (arr[i] - arr[i - 1] == mn) {
        		ans.push_back({arr[i - 1], arr[i]});
        	}
        }
        return ans;
    }
};