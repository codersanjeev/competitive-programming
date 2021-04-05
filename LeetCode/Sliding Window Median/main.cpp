class Solution {
  public:
	vector<double> medianSlidingWindow(vector<int> &nums, int k) {
		int n = nums.size(), i = 0, j = k - 1;
		vector<double> ans;
		vector<int> window(nums.begin() + i, nums.begin() + j + 1);
		sort(window.begin(), window.end());
		while (j < n) {
			ans.push_back(computeMedian(window));
			window.erase(lower_bound(window.begin(), window.end(), nums[i]));
			i++;
			j++;
			if (j < n) {
				window.insert(lower_bound(window.begin(), window.end(), nums[j]), nums[j]);
			}
		}
		return ans;
	}
  private:
	double computeMedian(const vector<int> &arr) {
		if (arr.size() % 2 == 1) {
			return arr[arr.size() / 2] * 1.0;
		} else {
			return 1.0 * ((long long) arr[arr.size() / 2] + (long long) arr[(arr.size() / 2) - 1]) * 0.5;
		}
	}
};