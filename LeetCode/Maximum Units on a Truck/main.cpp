class Solution {
  public:
	int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
		vector<pair<int, int>> arr;
		for (const auto &ele : boxTypes) {
			arr.push_back({ele[1], ele[0]});
		}
		sort(arr.begin(), arr.end());
		reverse(arr.begin(), arr.end());
		int ans = 0, i = 0;
		while (truckSize > 0 && i < arr.size()) {
			int curr = min(truckSize, arr[i].second);
			arr[i].second -= curr;
			ans += (arr[i].first * curr);
			truckSize -= curr;
			i++;
		}
		return ans;
	}
};